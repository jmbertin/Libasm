#include "libasm.h"
#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

void check_diff(void* a, void* b, int (*cmp)(void*, void*))
{
	if(cmp(a, b) == 0)
		printf("------------------------------ \033[32mDiff OK\033[0m ------------------------------\n");
	else
		printf("------------------------------ \033[31mDiff KO\033[0m ------------------------------\n");
}

int cmp_int(void* a, void* b) {
	int x = *(int*)a;
	int y = *(int*)b;

	if (x == y) return 0;
	else return 1;
}

int cmp_str(void* a, void* b) {
	char* x = (char*)a;
	char* y = (char*)b;

	return strcmp(x, y);
}

/*
**	Checks ft_strlen by comparing the result of ft_strlen and strlen
**	1. Empty string
**	2. Long string
**	3. String including special characters
*/
void ft_check_strlen(void)
{
	const char* test_str = "Hello, world!";
	const char* test_str2 = "";

	size_t len_ft = ft_strlen(test_str);
	size_t len = strlen(test_str);
	printf("- String : '%s'\n", test_str);
	printf("- strlen / ft_strlen : %zu / %zu\n", len, len_ft);
	check_diff(&len_ft, &len, cmp_int);

	len_ft = ft_strlen(test_str2);
	len = strlen(test_str2);
	printf("- String : '%s'\n", test_str2);
	printf("- strlen / ft_strlen : %zu / %zu\n", len, len_ft);
	check_diff(&len_ft, &len, cmp_int);

	/* Including special characters */
	const char* test_np_str = "Hello, world!\n\t\v\b\r\f\0";
	const char* test_np_str2 = "\n\t\v\b\r\f\0";

	len_ft = ft_strlen(test_np_str);
	len = strlen(test_np_str);
	printf("- String : 'Hello, world!\\n\\t\\v\\b\\r\\f\\0'\n");
	printf("- strlen / ft_strlen : %zu / %zu\n", len, len_ft);
	check_diff(&len_ft, &len, cmp_int);

	len_ft = ft_strlen(test_np_str2);
	len = strlen(test_np_str2);
	printf("- String : '\\n\\t\\v\\b\\r\\f\\0'\n");
	printf("- strlen / ft_strlen : %zu / %zu\n", len, len_ft);
	check_diff(&len_ft, &len, cmp_int);
}

/*
**	Checks ft_strcpy by comparing the result of ft_strcpy and strcpy
**	1. Copying a string to an empty string
**	2. Copying an empty string to a string
**	3. Copying a long string to a string
*/
void ft_check_strcpy(void)
{
	const char* src1 = "Hello, world!";
	char dest1[50];
	char dest_ft1[50];
	ft_strcpy(dest_ft1, src1);
	strcpy(dest1, src1);
	printf("- String    : '%s'\n", src1);
	printf("- ft_strcpy : %s\n", dest1);
	printf("- strcpy    : %s\n", dest_ft1);
	check_diff(dest1, dest_ft1, cmp_str);

	const char* src2 = "";
	char dest2[50];
	char dest_ft2[50];
	ft_strcpy(dest_ft2, src2);
	strcpy(dest2, src2);
	printf("- String    : '%s'\n", src2);
	printf("- ft_strcpy : '%s'\n", dest_ft2);
	printf("- strcpy    : '%s'\n", dest2);
	check_diff(dest_ft2, dest2, cmp_str);

	const char* src3 = "This is a very long string that's supposed to test the capabilities of your ft_strcpy implementation. Let's see if it can handle it.";
	char dest3[200];
	char dest_ft3[200];
	ft_strcpy(dest_ft3, src3);
	strcpy(dest3, src3);
	printf("- String    : '%s'\n", src3);
	printf("- ft_strcpy : '%s'\n", dest_ft3);
	printf("- strcpy    : '%s'\n", dest3);
	check_diff(dest_ft3, dest3, cmp_str);
}

/*
**	Checks ft_strcmp by comparing the result of ft_strcmp and strcmp
**	1. Empty string
**	2. Longer string
**	3. Shorter string
*/
void ft_check_strcmp(void)
{
	const char	*str1 = "Hello, world!";
	const char	*str_empty = "";
	const char	*str_longer = "Hello, world! How are you?";
	const char	*str_shorter = "Hello, world";

	int			result_ft, result;

	result_ft = ft_strcmp(str1, str_empty);
	result = strcmp(str1, str_empty);
	printf("- String1 : '%s', String2 : '%s'\n", str1, str_empty);
	printf("- strcmp / ft_strcmp : %d / %d\n", result, result_ft);
	check_diff(&result_ft, &result, cmp_int);

	result_ft = ft_strcmp(str1, str_longer);
	result = strcmp(str1, str_longer);
	printf("- String1 : '%s', String2 : '%s'\n", str1, str_longer);
	printf("- strcmp / ft_strcmp : %d / %d\n", result, result_ft);
	check_diff(&result_ft, &result, cmp_int);

	result_ft = ft_strcmp(str1, str_shorter);
	result = strcmp(str1, str_shorter);
	printf("- String1 : '%s', String2 : '%s'\n", str1, str_shorter);
	printf("- strcmp / ft_strcmp : %d / %d\n", result, result_ft);
	check_diff(&result_ft, &result, cmp_int);

	result_ft = ft_strcmp(str_empty, str_longer);
	result = strcmp(str_empty, str_longer);
	printf("- String1 : '%s', String2 : '%s'\n", str_empty, str_longer);
	printf("- strcmp / ft_strcmp : %d / %d\n", result, result_ft);
	check_diff(&result_ft, &result, cmp_int);

	result_ft = ft_strcmp(str_empty, str_shorter);
	result = strcmp(str_empty, str_shorter);
	printf("- String1 : '%s', String2 : '%s'\n", str_empty, str_shorter);
	printf("- strcmp / ft_strcmp : %d / %d\n", result, result_ft);
	check_diff(&result_ft, &result, cmp_int);

	result_ft = ft_strcmp(str_longer, str_shorter);
	result = strcmp(str_longer, str_shorter);
	printf("- String1 : '%s', String2 : '%s'\n", str_longer, str_shorter);
	printf("- strcmp / ft_strcmp : %d / %d\n", result, result_ft);
	check_diff(&result_ft, &result, cmp_int);
}

/*
**	Checks ft_strdup by comparing the result of ft_strdup and strdup
**	1. Normal string
**	2. Empty string
*/
void ft_check_strdup(void)
{
	/* First test */
	const char* src = "Hello, world!";
	const char* src2 = "";

	errno = 0;
	char* result = strdup(src);
	printf("- strdup : errno: %d (%s)\n", errno, strerror(errno));

	errno = 0;
	char* result_ft = ft_strdup(src);
	printf("- ft_strdup : errno: %d (%s)\n", errno, strerror(errno));

	printf("- String : '%s'\n", src);
	printf("- strdup / ft_strdup : '%s' / '%s'\n", result, result_ft);
	check_diff(result, result_ft, cmp_str);

	if (result_ft)
		free(result_ft);
	if (result)
		free(result);

	/* Second test */
	errno = 0;
	result = strdup(src2);
	printf("- strdup : errno: %d (%s)\n", errno, strerror(errno));

	errno = 0;
	result_ft = ft_strdup(src2);
	printf("- ft_strdup : errno: %d (%s)\n", errno, strerror(errno));

	printf("- String : '%s'\n", src2);
	printf("- strdup / ft_strdup : '%s' / '%s'\n", result, result_ft);
	check_diff(result, result_ft, cmp_str);

	if (result_ft)
		free(result_ft);
	if (result)
		free(result);
}

/*
**	Checks ft_read by comparing the result of ft_read and read
**	1. Empty file
*/
void ft_check_read_empty_file(void)
{
	int	fd = open("empty.txt", O_RDWR | O_CREAT, 0666);
	if (fd < 0)
	{
		perror("Error opening file for writing");
		return;
	}
	close(fd);

	fd = open("empty.txt", O_RDONLY);

	int		ft_fd = open("empty.txt", O_RDONLY);
	char	buffer[50] = {0};
	char	ft_buffer[50] = {0};

	ssize_t len = read(fd, buffer, 50);
	ssize_t len_ft = ft_read(ft_fd, ft_buffer, 50);
	buffer[49] = '\0';
	ft_buffer[49] = '\0';
	printf("- Read / ft_read : %zd / %zd\n", len, len_ft);
	printf("- Buffer : '%s'\n", buffer);
	printf("- ft_buffer : '%s'\n", ft_buffer);
	check_diff(buffer, ft_buffer, cmp_str);
	check_diff(&len, &len_ft, cmp_int);

	close(fd);
	close(ft_fd);
}

/*
**	Checks ft_read by comparing the result of ft_read and read
**	1. Nonexistent file
*/
void ft_check_read_nonexistent_file(void)
{
	int		fd = open("nonexistent.txt", O_RDONLY);
	char	buffer[50] = {0};
	char	ft_buffer[50] = {0};

	errno = 0;
	ssize_t len = read(fd, buffer, 49);
	printf("- Read : %zd, errno: %d (%s)\n", len, errno, strerror(errno));

	errno = 0; // reset errno
	ssize_t len_ft = ft_read(fd, ft_buffer, 49);
	printf("- ft_read : %zd, errno: %d (%s)\n", len_ft, errno, strerror(errno));

	buffer[49] = '\0'; // Ensure null termination after read
	ft_buffer[49] = '\0'; // Ensure null termination after ft_read

	printf("- Buffer : '%s'\n", buffer);
	printf("- ft_buffer : '%s'\n", ft_buffer);

	check_diff(buffer, ft_buffer, cmp_str);
	check_diff(&len, &len_ft, cmp_int);

	close(fd);
}

/*
**	Checks ft_read by comparing the result of ft_read and read
**	1. Read from stdin
*/
void ft_check_read_stdin(void)
{
	char buffer[50] = {0};
	char ft_buffer[50] = {0};

	printf("Please enter some input:\n");

	errno = 0;
	ssize_t len = read(0, buffer, 49);
	printf("- Read : %zd, errno: %d (%s)\n", len, errno, strerror(errno));

	printf("Please enter some input again:\n");

	errno = 0;
	ssize_t len_ft = ft_read(0, ft_buffer, 49);
	printf("- ft_read : %zd, errno: %d (%s)\n", len_ft, errno, strerror(errno));

	buffer[49] = '\0';
	ft_buffer[49] = '\0';

	printf("- Buffer : %s\n", buffer);
	printf("- ft_buffer : %s\n", ft_buffer);

	check_diff(buffer, ft_buffer, cmp_str);
	check_diff(&len, &len_ft, cmp_int);
}

/*
**	Checks ft_write by comparing the result of ft_write and write
**	1. Write to stdout
*/
void ft_check_write_stdout(void)
{
	const char* str = "Hello, world!\n";
	ssize_t len = write(1, str, strlen(str));
	printf("- Write    : %zd\n", len);
	ssize_t len_ft = ft_write(1, str, strlen(str));
	printf("- ft_write : %zd\n", len_ft);
	check_diff(&len, &len_ft, cmp_int);
}

/*
**	Checks ft_write by comparing the result of ft_write and write
**	1. Write to file
*/
void ft_check_write_file(void)
{
	const char* str = "Hello, world!";
	int fd = open("output.txt", O_RDWR | O_CREAT, 0666);
	ssize_t len = write(fd, str, strlen(str));
	printf("- Write    : %zd\n", len);
	lseek(fd, 0, SEEK_SET); // Reset file descriptor position
	ssize_t len_ft = ft_write(fd, str, strlen(str));
	printf("- ft_write : %zd\n", len_ft);
	check_diff(&len, &len_ft, cmp_int);
	close(fd);
}

/*
**	Checks ft_write by comparing the result of ft_write and write
**	1. Write to nonexistent file
*/
void ft_check_write_nonexistent_file(void)
{
	const char* str = "Hello, world!";
	int fd = open("nonexistent.txt", O_WRONLY);
	errno = 0; // Reset errno
	ssize_t len = write(fd, str, strlen(str));
	printf("- Write    : %zd, errno: %d (%s)\n", len, errno, strerror(errno));
	errno = 0; // Reset errno
	ssize_t len_ft = ft_write(fd, str, strlen(str));
	printf("- ft_write : %zd, errno: %d (%s)\n", len_ft, errno, strerror(errno));
	check_diff(&len, &len_ft, cmp_int);
}


int main(void)
{
	ft_write(1, "------------------------------ft_strlen------------------------------\n", 71);
	ft_check_strlen();
	ft_write(1, "\n------------------------------ft_strcpy------------------------------\n", 72);
	ft_check_strcpy();
	ft_write(1, "\n------------------------------ft_strcmp------------------------------\n", 72);
	ft_check_strcmp();
	ft_write(1, "\n------------------------------ft_strdup------------------------------\n", 72);
	ft_check_strdup();
	ft_write(1, "\n-------------------------ft_read_empty_file--------------------------\n", 72);
	ft_check_read_empty_file();
	ft_write(1, "\n----------------------ft_read_nonexistent_file-----------------------\n", 72);
	ft_check_read_nonexistent_file();
	ft_write(1, "\n---------------------------ft_read_stdin-----------------------------\n", 72);
	ft_check_read_stdin();
	ft_write(1, "\n--------------------------ft_write_stdout----------------------------\n", 72);
	ft_check_write_stdout();
	ft_write(1, "\n---------------------------ft_write_file-----------------------------\n", 72);
	ft_check_write_file();
	ft_write(1, "\n----------------------ft_write_nonexistent_file----------------------\n", 72);
	ft_check_write_nonexistent_file();

	return 0;
}
