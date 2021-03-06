/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_motion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 19:03:52 by amassnao          #+#    #+#             */
/*   Updated: 2019/05/01 19:04:01 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edit.h"

void	movecursor(t_tc *list, int x, int y)
{
	list->x = x;
	list->y = y;
	tputs(tgoto(tgetstr("cm", NULL), x, y), 1, ft_putcharc);
	(list->y + 1 > list->sh) ? tputs(tgetstr("do", NULL), 1, ft_putcharc) : 0;
}

void	up(t_tc *list)
{
	list->y--;
	tputs(tgetstr("up", NULL), 1, ft_putcharc);
}

void	down(t_tc *list)
{
	list->y++;
	tputs(tgetstr("do", NULL), 1, ft_putcharc);
}

void	left(t_tc *list, t_tcline **line)
{
	if ((*line)->cursor <= 0)
	{
		if ((*line)->prev)
		{
			prevline(list, line);
			movecursor(list, list->x + (*line)->len % list->sw,
					list->y + (*line)->len / list->sw);
			(*line)->cursor = (*line)->len;
		}
		return ;
	}
	(*line)->cursor--;
	if (list->x-- == 0)
		movecursor(list, list->sw - 1, list->y - 1);
	else
		tputs(tgetstr("le", NULL), 1, ft_putcharc);
}

void	right(t_tc *list, t_tcline **line)
{
	if ((*line)->cursor >= (*line)->len)
	{
		if ((*line)->next)
		{
			nextline(list, line);
			movecursor(list, list->x - (*line)->cursor % list->sw,
					list->y - (*line)->cursor / list->sw);
			(*line)->cursor = 0;
		}
		return ;
	}
	(*line)->cursor++;
	if (list->x++ == list->sw - 1)
		movecursor(list, 0, list->y + 1);
	else
		tputs(tgetstr("nd", NULL), 1, ft_putcharc);
}
