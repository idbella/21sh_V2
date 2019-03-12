/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:46:13 by sid-bell          #+#    #+#             */
/*   Updated: 2019/03/12 05:28:33 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

int main(int argc, char **argv, char **env)
{
	char		*line;
	t_params	params;

	argc = 0;
	argv = NULL;
	params.env = NULL;
	params.commands = NULL;
	ft_parse_env(env, &params);
	ft_putstr("$> ");
	while (get_next_line(0, &line) > 0)
	{
		ft_handle_qoutes(&line);
		ft_split(line, &params);
		ft_init_exec(&params);
		ft_putstr("$> ");
	}
}
