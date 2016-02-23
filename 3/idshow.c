#include <unistd.h>
#include <sys/fsuid.h>
#include <limits.h>
#include "ugid_functions.h"
#include "tlpi_hdr.h"

#define SG_SIZE (NGROUPS_MAX + 1)

int main(int argc, char *argv[])
{
	uid_t ruid, euid, suid, fsuid;
	gid_t rgid, egid, sgid, fsgid;
	gid_t suppGroups[SG_SIZE];
	int numGroups, j;
	char *p;

	if(getresuid(&ruid, &euid, &suid) == -1)
		errExit("getresuid");
	if(getresgid(&rgid, &egid, &sgid) == -1)
		errExit("getresgid");
	
	fsuid = setfsuid(0);
	fsgid = setfsgid(0);
	
	printf("UID: ");
	p = userNameFromId(ruid);
	printf("real = %s (%ld); ", (p == NULL) ? "???" : p,(long)ruid);
	
	p = userNameFromId(euid);
	printf("eff = %s (%ld); ", (p == NULL) ? "???" : p, (long)euid);

	p = userNameFromId(suid);
	printf("eff = %s (%ld); ", (p == NULL) ? "???" : p, (long)suid);
	return 0;
}
