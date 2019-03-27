/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_21sh.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 21:47:53 by sid-bell          #+#    #+#             */
/*   Updated: 2019/03/27 21:40:17 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_21SH_H
# define FT_21SH_H
# include "libft/libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <termios.h>
# define C_UP 4283163
# define C_DOWN 4348699
# define C_RIGHT 4414235
# define C_LEFT 4479771
# define END_KEY 4610843
# define HOME_KEY 4741915
# define NEXT_WORD 9
# define PREVIOUS_WORD 21
# define SELECT 2	/* C-B */
# define COPY 6		/* C-F */
# define PAST 22	/* C-V */
# define CUT 16		/* C-P */
# define UP_LINE 1	/* C-A */
# define DOWN_LINE 14	/* C-N */
# include <sys/ioctl.h>
# include <termcap.h>
# define APPEND O_APPEND|O_CREAT|O_WRONLY
# define TRUNC O_CREAT|O_WRONLY|O_TRUNC

typedef struct stat	t_stat;
typedef struct	s_command
{
	char	**argv;
	t_list	*outlist;
}				t_command;

typedef	struct s_oldline
{
	char *text;
	char *prefix;
}				t_oldline;

typedef struct	s_line
{
	int		c;
	char	*prefix;
	char	*data;
	int		cursor;
	int		width;
	char	*delete;
	char	*mv_up;
	char	*mv_left;
	char	*mv_right;
	char	*mv_down;
	char	*reverse_v;
	char	*stop_v;
	int		select_mode;
	int		select_start;
	char	*clipboard;
	t_list	*old_lines;
}				t_line;
typedef struct	s_outfile
{
	char		*name;
	int			open_mode;
	int			fd_src;
	int			fd_dest;
}				t_outfile;

typedef struct	s_params
{
	t_list			*env;
	t_list		*commands;
	int			savedfd[3];
	int			pipefd[2];
	int			currentfd[3];
	int			pid;
	int			err;
}				t_params;

typedef struct		s_env
{
	char			*key;
	char			*value;
}					t_env;
void			ft_env(t_list *list);
char			*ft_get_env_key(char *key, t_list *list);
char			**ft_get_env(t_list *list);
void			ft_parse_env(char **env, t_params *params);
void			ft_setenv(char *key, char *value, t_params *params);
void			ft_unsetenv(char *key, t_params *params);
void			ft_parse(char *line, t_params *params);
char			*ft_delchar(char **str, int index);
char			*ft_insertchar(char **src, char c, int index);
char			*ft_joinargs(char *str);
void			ft_handle_qoutes(char **line);
void			ft_split(char *line, t_params *params);
void			ft_qoutes(char c, int *qoute);
int				ft_is_special_key(char c);
char			*ft_remove_wsapces(char *str);
int				ft_isbuilt_in(char *name);
void			ft_built_in(t_command *cmd, t_params *params);
void			ft_echo(t_command *cmd);
void			ft_exec(t_params *params, t_list *commands);
void    		ft_init_exec(t_params *params);
int 			ft_is_token(char *str);
int				ft_countargs(char **args);
char			*ft_insert_str(char *str1, char *filler, int index);
void			ft_split(char *str, t_params *params);
char			**ft_get_args(t_command *cmd, char **args, int *i);
int				ft_is_aggregation(char *current);
int				ft_get_fd_src(char *str);
int				ft_get_fd_dest(char *str);
int				ft_isvalidred(char *str);
int				ft_is_redirection(char *str);
int				ft_lex(char *str, t_list **lst);
void			ft_fd_or_file(char **line, int i);
char			*ft_find_file(char *file, t_list *list);
char			**ft_getpaths(t_list *list);
t_stat			*ft_exist(char *file);
void			ft_addfile(t_command *command, char **commands, int i);
void			ft_addaggr(t_command *command, char *cmd);
int     		ft_get_redirections(char **commands, t_command *command, int i);
char    		**ft_lst_to_arr(t_list *list);
int				ft_get_width();
int				ft_put(int c);
void			ft_backspace(t_line *line);
void			ft_print(t_line *line);
char			*ft_strinsert(char *str1, char *filler, int index);
char			*ft_getline();
void			ft_special_keys(t_line *line);
void			ft_next_word(t_line *line);
void			ft_previous_word(t_line *line);
int				ft_get_nline(t_line *line);
int				ft_get_cline(t_line *line);
void			ft_cut(t_line *line);
void			ft_copy(t_line *line);
void			ft_past(t_line *line);
void			ft_select(t_line *line);
void			ft_clearline(t_line *line);
void			ft_move_cursor(t_line *line);
void			ft_cursor(t_line *line);
int				ft_cloumn(t_line *line);
#endif
