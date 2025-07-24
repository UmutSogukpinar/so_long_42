#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

char	*get_next_line(int fd);

// ====================== Utils ======================

void	clear_get_next_line(int fd);
int		ft_is_newline_char(const char *s);
char	*ft_update_repo(char *total_line, char *repo);

#endif