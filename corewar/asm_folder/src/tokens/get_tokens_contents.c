/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens_contents.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 18:08:11 by user42            #+#    #+#             */
/*   Updated: 2020/04/21 22:55:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

int		get_token_value(t_cwr *cwr, t_line *line, t_token *token)
{
	int		ret;

	if (token->value[0] == LABEL_CHAR)
	{
		++token->value;
		ret = add_ref(cwr, &line->arg[line->arg_nb - 1], token);
		return (ret);
	}
	line->arg[line->arg_nb - 1] = ft_atoi(token->value);
	return (EXIT_SUCCESS);
}

int		get_token_arg(t_cwr *cwr, t_line *line, t_token *token)
{
	if (token->content[0] == 'r')
	{
		line->arg_type[line->arg_nb] = T_REG;
		token->value = token->content + 1;
		token->byte_size = 1;
	}
	else if (token->content[0] == DIRECT_CHAR)
	{
		line->arg_type[line->arg_nb] = T_DIR;
		token->value = token->content + 1;
		token->byte_size = DIR_SIZE / (line->rules->dir_size + 1);
	}
	else
	{
		line->arg_type[line->arg_nb] = T_IND;
		token->value = token->content;
		token->byte_size = IND_SIZE;
	}
	if (!(line->arg_type[line->arg_nb] & line->rules->arg_type[line->arg_nb]))
		return (cwr_error(cwr, "bad argument type: ", CWR_ERR_TOKEN));
	line->arg_index_token[line->arg_nb] = line->token_pos;
	++line->arg_nb;
	return (get_token_value(cwr, line, token));
}

int		get_token_inst(t_cwr *cwr, t_line *line, t_token *token)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (!ft_strncmp(token->content, g_op_tab[i].name, token->len)
			&& token->len == ft_strlen(g_op_tab[i].name))
		{
			line->rules = &g_op_tab[i];
			line->op_code = line->rules->code;
			if (line->rules->has_coding_byte)
				token->byte_size = 2;
			else
				token->byte_size = 1;
			return (EXIT_SUCCESS);
		}
		++i;
	}
	return (cwr_error(cwr, "bad instruction: ",
		CWR_ERR_TOKEN));
}

int		get_tokens_contents(t_cwr *cwr, t_line *line)
{
	t_token	*token;
	int		ret;

	ret = 0;
	line->token_pos = line->first_token;
	while (line->token_pos < TOKEN_MAX)
	{
		token = &line->token[line->token_pos];
		if (token->type == TOKEN_LABEL)
			ret = add_label(cwr, token, cwr->prog_line_start);
		else if (token->type == TOKEN_ARG)
			ret = get_token_arg(cwr, line, token);
		else if (token->type == TOKEN_INST)
			ret = get_token_inst(cwr, line, token);
		if (ret != EXIT_SUCCESS)
			return (ret);
		cwr->prog_pos += token->byte_size;
		++line->token_pos;
	}
	cwr->prog_pos = cwr->prog_line_start;
	return (EXIT_SUCCESS);
}
