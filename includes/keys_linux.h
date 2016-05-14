/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_linux.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:51:46 by tboos             #+#    #+#             */
/*   Updated: 2016/05/11 14:52:52 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_LINUX_H
# define KEY_LINUX_H

# define HELP_MESS "Help : Ctrl-H"
# define HELP_MESS_LEN 13
# define HELP_PAGE1 "   __ _              _           _\n"
# define HELP_PAGE2 "  / _| |            | |         | |\n"
# define HELP_PAGE3 " | |_| |_   ___  ___| | ___  ___| |_\n"
# define HELP_PAGE4 " |  _| __| / __|/ _ \\ |/ _ \\/ __| __|\n"
# define HELP_PAGE5 " | | | |_  \\__ \\  __/ |  __/ (__| |_ \n"
# define HELP_PAGE6 " |_|  \\__| |___/\\___|_|\\___|\\___|\\__|\n"
# define HELP_PAGE7 "       ______\n"
# define HELP_PAGE8 "      |______|\n\n"
# define HELP_PAGE9 "\u2191\u2193 : Move up and down\n"
# define HELP_PAGE10 "\u2190\u2192 : Move on same raw\n"
# define HELP_PAGE11 "Space : Select current\nHome-End : Go to first or last\n"
# define HELP_PAGE12 "Delete-Suppr : Remove current from list\n"
# define HELP_PAGE13 "Clrl-A/D : Select/Deselect All\n"
# define HELP_PAGE14 "Letter Chain : Case sensitive search\n"
# define HELP_PAGE15 "Enter : Confirm selection"
# define CTH 0x08 //Ctrl-H
# define CLF 0x0A //\n
# define SUP 0x7E335B1B //sup
# define CHT 0x09 //\t
# define DEL 0x7F //DEL
# define LEF 0x445B1B //left
# define RIG 0x435B1B //right
# define UPP 0x415B1B //up
# define DOW 0x425B1B //down
# define SPA ' ' //space
# define ESC 0x1B //escape
# define CTA 0x01 //Ctrl-A
# define CTD 0x04 //Ctrl-D
# define CLEF 0x44353B315B1B //CTRL left
# define CRIG 0x43353B315B1B //CTRL up
# define CUPP 0x41353B315B1B //CTRL right
# define CDOW 0x42353B315B1B //CTRL down
# define END 0x464F1B //end
# define HOM 0x484F1B //home
# define NUL 0x00 //\0

#endif
