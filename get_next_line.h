
# ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# ifndef buffer_size
# define buffer_size 42

#endif

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char    *get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dst, const void *src);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *s);

#endif