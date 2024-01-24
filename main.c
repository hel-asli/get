/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-asli <hel-asli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 01:58:44 by hel-asli          #+#    #+#             */
/*   Updated: 2024/01/24 03:38:51 by hel-asli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void foo() 
{
    system("leaks a.out");
}

int main(void)
{
    atexit(foo);
    int fd = open("file.txt", O_RDONLY);

    // close(fd);
    char *line = get_next_line(fd);
    // while (line)
    // {
    //     printf("%s", line);
    //     free(line);
    //     line = get_next_line(fd);
    // }
    printf("%s", line);
    free(line);
    

    // free(line);
}