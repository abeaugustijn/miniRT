/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:36:05 by aaugusti          #+#    #+#             */
/*   Updated: 2019/12/21 12:11:54 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

/*
**	Checks if there is a '\n' byte in a string.
**
**	@param {char *}str - the string to search
**
**	@returns {bool} - true if a '\n' is found before the end of the string.
*/

bool		gnl_hasnewline(char *str)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE && str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/*
**	Get the amount of bytes before a specific char or '\0' is encountered.
**
**	@param {char *} str - the string to get the length of
**	@param {char} c - the char to find
**
**	@returns {size_t} - the amount of bytes before 'c' or '\0'.
*/

size_t		gnl_strlenc(char *str, char c)
{
	size_t	res;

	res = 0;
	while (str[res] && str[res] != c)
		res++;
	return (res);
}

/*
**	Shift 'buf' so that it is ready for the next cycle. The effect of this
**	function is that it will basically get rid of all the bytes before the
**	first '\n' char. It will shift everything that comes after that to the
**	beginning of the buffer. to_return is there so that this function could be
**	used in a return statement. If no '\n' char is found, the whole buffer is
**	effectively cleared.
**
**	@param {char *} buf - the buffer to shift
**	@param {int} to_return
**
**	@returns {int} - to_return without any changes
*/

int			gnl_shiftbuf(char *buf, int to_return)
{
	size_t	start;
	size_t	i;
	size_t	n;

	start = 0;
	n = gnl_strlenc(buf, 0);
	while (buf[start] != '\n' && start < n)
		start++;
	start++;
	if (!n && buf[0] == '\n')
		n++;
	i = 0;
	while (start < n)
	{
		buf[i] = buf[start];
		i++;
		start++;
	}
	while (i < n)
	{
		buf[i] = 0;
		i++;
	}
	return (to_return);
}

/*
**	Concatenate two strings. It will concatenate 'buf' after '*res' and the
**	length of both is determined by the first encounter of a '\0' or a '\n'
**	byte. In case of a failed malloc the function will free '*res'.
**
**	@param {char **} res - a pointer to the string which will be the first part
**		of the concatenated string. The resulting string will also be stored at
**		this address.
**	@param {char *} buf - the second part of the final string.
**
**	@returns {bool} - will be true if the malloc failed. False when everything
**		went fine.
*/

bool		gnl_strlcat(char **res, char *buf)
{
	size_t	og_len;
	size_t	buf_len;
	size_t	i;
	char	*old_res;

	og_len = gnl_strlenc(*res, '\n');
	buf_len = gnl_strlenc(buf, '\n');
	old_res = *res;
	*res = (char *)malloc((og_len + buf_len + 1) * sizeof(char));
	if (!*res)
		return (gnl_free(old_res, true));
	(*res)[og_len + buf_len] = 0;
	i = 0;
	while (i < og_len)
	{
		(*res)[i] = old_res[i];
		i++;
	}
	free(old_res);
	while (i < og_len + buf_len)
	{
		(*res)[i] = buf[i - og_len];
		i++;
	}
	return (false);
}

/*
**	Duplicate the string currently in the buffer and set a flag to indicate
**	whether the get_next_line function should return. gnl_shiftbuf is called
**	to shift the buffer to prepare for the next read.
**
**	@param {char *} buf - the string to duplicate
**	@param {int *} force_ret - pointer to the flag which indicates whether
**		get_next_line should return.
**
**	@returns {char *} - the new string. NULL if malloc failed
*/

char		*gnl_strdup(char *buf, bool *force_ret)
{
	size_t	len;
	size_t	i;
	char	*res;

	len = 0;
	while (buf[len] && buf[len] != '\n')
		len++;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = 0;
	i = 0;
	while (i < len)
	{
		res[i] = buf[i];
		i++;
	}
	if (gnl_hasnewline(buf))
		*force_ret = true;
	else if (len > 0)
		gnl_shiftbuf(buf, 0);
	return (res);
}
