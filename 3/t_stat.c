#define _BSD_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include "file_perms.h"
#include "tlpi_hdr.h"

static void displayStatInfo(const struct stat *sb)
{
	printf("File type:      ");

	switch (sb->st_mode & S_IFMT){
		case S_IFREG: printf("regular file\n");
					  break;
		case S_IFDIR: printf("directory\n");
					  break;
		case S_IFCHR: printf("character device\n");
					  break;
		case S_IFBLK: printf("block device\n");
					  break;
		case S_IFLNK: printf("symboilc link\n");
					  break;
		case S_IFIFO: printf("FIFO or Pipe\n");
					  break;
		case S_IFSOCK: printf("socket\n");
					   break;
		default: printf("Unknow!\n");
	}

	printf("Device containing i-node: major = %ld  minor =%ld\n", major(sb->st_dev), minor(sb->st_dev));
}

