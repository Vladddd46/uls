/*  Libriaries  */
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <pwd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/errno.h>
#include <string.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <sys/xattr.h>
#include <sys/acl.h>
#include <sys/types.h>
/* ------------- */



#define MINORBITS       24
#define MINORMASK       ~(0xFF << MINORBITS)
#define MAJOR(dev)      ((unsigned int) ((dev) >> MINORBITS))
#define MINOR(dev)      ((unsigned int) ((dev) & MINORMASK))

#define MX_S_IRUSR       00400
#define MX_S_IWUSR       00200
#define MX_S_IXUSR       00100
#define MX_S_IRGRP       00040
#define MX_S_IWGRP       00020
#define MX_S_IXGRP       00010
#define MX_S_IROTH       00004
#define MX_S_IWOTH       00002
#define MX_S_IXOTH       00001



/* lists */
//files list
typedef struct s_files {
	char *file_name;
	char type;
    struct stat stats;
	struct s_files *next;
}   t_files;
//directory list
typedef struct s_dirs {
	char *dir_name;
	char type;
	int empty;
	t_files *files;
	struct s_dirs *next;
}   t_dirs;
t_dirs *mx_create_tdirs(char *dir_name);
void mx_push_back_tdirs(t_dirs **list, char *dir_name);
t_files *mx_create_tfiles(char *file_name);
void mx_push_back_tfiles(t_files **list, char *file_name);
t_files *mx_files_list_maker(char *dir_name, char *flags);



/* recursion */
void mx_recursion(char **specified_dirs, char *flags);



/* main */
void mx_second_section(t_files *files, char *flags, char* dir);
int mx_return_value(int argc, char **argv);
int mx_error_printer(char *dir_name);


/* flags parsing */
char *mx_flags_parser(int argc, char **argv);



/* directories */
char **mx_specified_directories(int argc, char **argv);
int mx_argv_index(int argc, char *argv[]);
void mx_directories(int argc, char **argv, char *flags);
int mx_permission_denied(char *dir_name);
// void mx_permission_denied_error(char *dir_name);
int mx_error(char *dir_name);



/* files */ 
char **mx_list_of_files(char *dir_name, char *flags, char* file_path);



/* ls specific functional */
char **mx_list_of_dirs(char *dir);
char mx_file_type(char *file_path, struct stat Stat);
int mx_file_exists(char *file);
int mx_a_checker(char *dir_name, char *flags);
int mx_is_directory(char *dir_name);
char *mx_link(char *file, struct stat sb);
int mx_count_list(t_files* list);
char mx_type(char *file_path);



/* multifunctions */
int mx_strlen(const char *s);
char *mx_strjoin(char *s1, char *s2);
char *mx_strnew(int size);
char *mx_strcpy(char *dst, const char *src);
int mx_is_in_arr(char *s, char c);
int mx_strcmp(const char *s1, const char *s2);
int mx_char_in_arr_counter(char *arr, char c);
char *mx_copystr(char *str);
char **mx_new_strarr(int number_of_str);
int mx_strarr_size(char **arr);
char **mx_strarr_join(char **arr1, char **arr2);
void mx_quicksort_strarr(char **arr, int left, int right);
char *mx_three_join(char *str1, char *str2, char *str3);
char *mx_string_copy(char *str);
void mx_print_strarr(char **strarr);
void mx_printstr(const char *s);
char *mx_file_name_retriever(char *file_path);
char *mx_itoa(int number);



/* freeshers */
void mx_tfiles_freesher(t_files *files);
void mx_free_strarr(char **strarr);


/* Debug */
void mx_files_printer(t_files *files);



/* flags */
void mx_flag_m(t_files *files, char *flags, char *dir);
void mx_flag_G(t_files* list, char* dir);
void mx_flag_l_output(t_files *l, char *dir, char *flags);  //------------// *
char* mx_get_stgid(t_files *list);				 							 // *
int mx_getint_len (int num);					 							 // *
char *mx_getuser(uid_t uid);					 							 // *
char* mx_convert_date(char* buff, t_files* list);                            // *
char* mx_get_size(t_files* list, char* dir, int* size_all);					 // *
char *mx_file_mode(struct stat Stat, char *name, char *path);
char* mx_itoas_addition(int number, long number2, int len);
int* mx_each_l_add(int* l, t_files* tmp, char* d);
char* mx_file_mode_add(struct stat Stat, char *mode);
void mx_flag_l_out_add(t_files *l, char *dir, char *flags, int l1[9], int l2[8]);
char* mx_high_minor(char* hexadecimalNumber, t_files* list, char* major, char* minor);
char* mx_get_size_if(t_files* list, char* hexadecimalNumber, int* size_all); // *
int* mx_longest_devs(t_files* list, char* directory_name, int* length_of_all);// *
void mx_print_total(t_files *list);  //--------------------------------------// *
void mx_pure_output(t_files *list, char *flags, char *dir);	//-----------------------------------------// *
int mx_rest(t_files* list, int cols);		
void mx_pure_addition(t_files *list, char *arr[mx_count_list(list)], int cols, int i);
void mx_super_print(t_files *list, int i, char *arr[mx_count_list(list)], char *flags, char *dir);							      // *
char **mx_sort_output(int count, t_files* list, int cols, char *s[count]);//-// *
void mx_flag_p(t_files *file, char *flags);//---//*
void mx_flag_p_for_pureoutput(t_files *list);//-//*
void mx_minus_one(t_files *files, char *flags, char *dir);
t_files *mx_flag_d(char **specified_dirs);


void mx_newline(char **specified_dirs, int i);










