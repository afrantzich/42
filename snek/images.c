/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 15:17:06 by afrantzi          #+#    #+#             */
/*   Updated: 2018/07/01 15:27:26 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**test_img(void)
{
	/* XPM */
	static char *image[] = {
	/* <Values> */
	/* <width/columns> <height/rows> <colors> <chars per pixel>*/
	"48 4 2 1",
	/* <Colors> */
	"a c #ffffff",
	"b c #000000",
	/* <Pixels> */
	"abaabaababaaabaabababaabaabaababaabaaababaabaaab",
	"abaabaababaaabaabababaabaabaababaabaaababaabaaab",
	"abaabaababaaabaabababaabaabaababaabaaababaabaaab",
	"abaabaababaaabaabababaabaabaababaabaaababaabaaab"
	};
	return (image);
}
