/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_com.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:16:36 by muteza            #+#    #+#             */
/*   Updated: 2023/01/16 15:32:15 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// int	make_pipe(int i, t_data *data)
// {
// 	return (0);
// }

// void	get_command_in_tab(t_data *data, t_lst *lst, int i)
// {
// }

// void	pipex_mod(t_data *data, int i, t_lst *lst, int k)
// {
// }

void	init_fork_pipe(t_lst *lst, t_data *data)
{
	int		i;
	t_lst	*tmp;
	int		k;

	tmp = lst;
	i = 0;
	data->save_out = dup(1);
	data->save_in = dup(0);
	// put_lst_in_tab(data, i, tmp);
	//data->id = malloc(sizeof(pid_t) * (data->maxindex + 1));
	while (tmp)
	{
		// for (; tmp != NULL; tmp = tmp->next)
		// printf("tmp == %s\n", tmp->content);
			
		if (!tmp->next)
		{
			k = 1;

			printf("ADSDA\n");
			put_lst_in_tab(data, i, tmp);
			no_more_command(data, tmp);
			break ;
		}
		else
		{
			// printf("suivant == %s\n", tmp->next->content);
			k = 0;
			put_lst_in_tab(data, i, tmp);
			more_pipe(data, tmp);
			i++;
			// printf("ADBAKWDJKAHW\n");
			tmp = tmp->next;
		}
	}
	// wait(&data->id[i]);
	// printf("AA\n");
	// while (1);
	exit (0);
}


// 	int ret;
// pipe ->
// 	int fd[2]
// 	pipe(fd)
// 	fork()
// 	(pid == 0)
// 	{
// 		ret = dup2(fd[0], STDIN_FILENO); // on change l'entree vers la pipe
// 		if (ret == -1)
// 			exit_error();
// 		close(fd[0]);
// 		close(fd[1]);
// 		redirection();
// 		execve();			
// 	}
// 	dup2(fd[1], 1);
// 	close(fd[1]);
// 	close(fd[0]);
	
// 	waitpid(pid, &retour, NULL)
	
// 	//

// 	dup2(fd[0], save_0);
// 	dup2(fd[1], save_1);
// 	close(fd[0]);
// 	close(fd[1]);
// 	while(1)
// 		if (wait() == -1)
// 			break;

			
	





	
void	put_lst_in_tab(t_data *data, int i, t_lst *tmp)
{
	int		k;

	k = 0;
	while (tmp->next && (tmp->index != i))
	{
		tmp = tmp->next;
		i++;
	}
	printf("command actuel : %s\n", tmp->content);
	data->str = ft_split(tmp->content, ' ');
}

void	pipe_com(t_lst *lst, t_data *data)
{
	init_fork_pipe(lst, data);
	// printf("AAA\n");
}
