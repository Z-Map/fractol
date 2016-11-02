/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 21:00:05 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/01 22:30:53 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		parser_doubledasharg(t_frc *frc, const char *arg)
{
	if (!ft_strcmp(arg, "help"))
		frc->params.flags |= HELP_MODE;
	else if (!ft_strcmp(arg, "gradient"))
		frc->params.gradient.mode = UNICOLOR;
	else if (!ft_strcmp(arg, "dualgradient"))
		frc->params.gradient.mode = DUALCOLOR;
	else if (!ft_strcmp(arg, "huegradient"))
		frc->params.gradient.mode = HUEGRADIENT;
	else if (!ft_strcmp(arg, "huetriplegrad"))
		frc->params.gradient.mode = HUETRIGRAD;
	else if (!ft_strcmp(arg, "hybrid"))
		frc->params.gradient.mode = HSGRAD;
	else if (!ft_strcmp(arg, "fire"))
		frc->params.gradient.mode = FIREGRAD;
	else if (!ft_strcmp(arg, "staticgradient"))
		frc->params.gradient.mode = STATICGRADIENT;
	else if (!ft_strcmp(arg, "stasatgradient"))
		frc->params.gradient.mode = STASATGRADIENT;
	else if (!ft_strcmp(arg, "manual"))
		frc->params.flags &= ~AUTOREFRESH;
	else if (!ft_strcmp(arg, "nothread"))
		frc->params.flags &= ~MULTITHREAD;
	else if (!ft_strncmp(arg, "voidcol=", 8))
		frc->params.gradient.voidcol = get_col(arg + 8);
}

static void		parser_dasharg(t_frc *frc, const char *arg)
{
	t_ui		c;

	c = (t_ui)(-1);
	if ((c = (t_ui)ft_stridx(arg, 'v')) != (t_ui)(-1))
		frc->params.gradient.voidcol = get_col(&(arg[c + 1]));
	if ((t_ui)ft_stridx(arg, (int)'d') < c)
		frc->params.flags |= DISP_KCODE;
	if ((t_ui)ft_stridx(arg, (int)'g') < c)
		frc->params.gradient.mode = UNICOLOR;
	if ((t_ui)ft_stridx(arg, (int)'G') < c)
		frc->params.gradient.mode = DUALCOLOR;
	if ((t_ui)ft_stridx(arg, (int)'h') < c)
		frc->params.gradient.mode = HUEGRADIENT;
	if ((t_ui)ft_stridx(arg, (int)'H') < c)
		frc->params.gradient.mode = HUETRIGRAD;
	if ((t_ui)ft_stridx(arg, (int)'f') < c)
		frc->params.gradient.mode = FIREGRAD;
	if ((t_ui)ft_stridx(arg, (int)'s') < c)
		frc->params.gradient.mode = STATICGRADIENT;
	if ((t_ui)ft_stridx(arg, (int)'S') < c)
		frc->params.gradient.mode = STASATGRADIENT;
	if ((t_ui)ft_stridx(arg, (int)'m') < c)
		frc->params.flags &= ~AUTOREFRESH;
	if (ft_strnstr(arg, "nt", c))
		frc->params.flags &= ~MULTITHREAD;
}

static void		parse_an_arg(t_frc *frc, const char *arg)
{
	const char	*words[] = {"mandlebrot", "julia", "burningship", "X",
		"custom", "luna", "cube", "multibrot(mu)"};
	const char	*shortw[] = {"mb", "ju", "bs", "x", "cm", "lu", "cb", "mu"};
	int			i;

	i = -1;
	if (!ft_strncmp(arg, "--", 2))
		parser_doubledasharg(frc, arg + 2);
	else if (*arg == '-')
		parser_dasharg(frc, arg + 1);
	else if (!ft_strncmp(arg, "0x", 2))
		parse_col(frc, arg + 2);
	else
	{
		while (++i < FRACNUM)
			if (!ft_strcmp(arg, words[i]) || !ft_strcmp(arg, shortw[i]))
				frc->params.ftype = i;
	}
}

static int		display_help(int i)
{
	if (i == -1)
		ft_putendl_fd("\e[1;31mFractal name missing or uknown !\e[0m", 2);
	ft_putendl("Usage :\n fractol [OPTION] [COLOR]... FRACTAL\n");
	ft_putstr("Fractal :\n mandlebrot(mb), julia(ju), burningship(bs), ");
	ft_putendl("X(x), custom(cm), luna(lu), cube(cb), multibrot(mu)\n");
	ft_putendl("Color :\n -v=[0x](%x|%X)\t\tset void color");
	ft_putstr(" COLOR=0x(%x|%X)\tlast specified set c2,");
	ft_putendl(" the first set c1 if more than one are specified\n");
	ft_putendl("Gradient option :\n"HGG HGGG HGH HGHH HG_S HGS HGF HGHHH);
	ft_putendl("Other option :\n -nt\t\t\tno threaded render");
	ft_putendl(" -m\t\t\tmanual render ('Q' key)");
	ft_putendl(" -d\t\t\tdisplay debug of input event");
	ft_putendl(" --help\t\t\tdisplay this help");
	return (i);
}

int				parse_args(t_frc *frc, int ac, char **av)
{
	int			i;

	frc->params.gradient.mode = NOTSET;
	frc->params.gradient.voidcol = 0;
	frc->params.gradient.start = draw_col(255, 174, 37);
	frc->params.gradient.end = draw_col(42, 0, 0);
	frc->params.ftype = NO_FRAC;
	frc->params.flags = MULTITHREAD | AUTOREFRESH | HIDE_HUD;
	i = 0;
	while (++i < ac)
		parse_an_arg(frc, av[i]);
	if (frc->params.gradient.mode == NOTSET)
		frc->params.gradient.mode = DUALCOLOR;
	if ((frc->params.ftype == NO_FRAC) && !(frc->params.flags & HELP_MODE))
		return (display_help(-1));
	else if (frc->params.ftype == NO_FRAC)
		return (display_help(0));
	return ((frc->params.flags & HELP_MODE) ? display_help(1) : 1);
}
