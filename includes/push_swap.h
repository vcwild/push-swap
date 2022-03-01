/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:47:17 by vwildner          #+#    #+#             */
/*   Updated: 2022/02/17 21:54:52 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP

/* libraries */
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>

/* internal libraries */
# include <libft.h>
# include <get_next_line.h>

/* handlers.c */
/**
 * @brief Handles the program exiting
 *
 * @param s The error message to be printed
 */
void	handle_exit(const char *s);

/**
 * @brief Handles file read and write flags
 *
 * @param file The file to be handled
 * @param oflag The open permissions
 * @return int Returns the file descriptor for the open file
 */
int		handle_rw(char *file, int oflag);

/**
 * @brief Gets the absolute path to the cmd
 *
 * @param cmd The command to be searched inside the path
 * @param path The current environment path
 * @return char*
 */
char	*get_abspath(char *cmd, const char *path);

/**
 * @brief Executes a subrountine to read the standard input
 *
 * @param argv The delimiter to stop reading the standard input
 */
void	exec_read_stdin(char *delim);

/**
 * @brief Executes the command
 *
 * @param cmd The command to be executed
 * @param envp The environment where the command is located
 */
void	exec_cmd(char *cmd, char *envp[]);

/**
 * @brief Executes the intermediate pipe redirections
 *
 * @param cmd The command to be executed
 * @param envp The environment where the command is located
 */
void	exec_redir(char *cmd, char *envp[]);

/**
 * @brief Merges the two strings with a '/' in between
 *
 * @param origin The first string
 * @param other The second string
 * @return char* Returns the merged string
 */
char	*help_slash_merge(char const *origin, char const *other);

/**
 * @brief Parses the input while in here_doc mode
 *
 * @param delim The delimiter to stop reading the input
 * @param fd The file descriptor to output the parsed input
 */
void	parse_here_doc(char *delim, int *fd);

#endif
