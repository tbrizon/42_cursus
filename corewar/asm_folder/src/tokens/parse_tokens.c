/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skpn <skpn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 13:45:32 by sikpenou          #+#    #+#             */
/*   Updated: 2020/04/17 17:35:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

void	parse_token_arg_qualifiers(t_cwr *cwr, t_token *token)
{
	++token->len;
	--cwr->pos;
	if (cwr->file[cwr->pos] == LABEL_CHAR
		&& cwr->file[cwr->pos - 1] == DIRECT_CHAR)
	{
		++token->len;
		--cwr->pos;
	}
}

void	parse_token_arg(t_cwr *cwr, t_token *token)
{
	char	c;

	if (cwr->line->token_pos == TOKEN_MAX - 1 || (token + 1)->type == TOKEN_SEP)
		token->type = TOKEN_ARG;
	else
		token->type = TOKEN_INST;
	while (cwr->pos > 0 && (c = cwr->file[cwr->pos - 1])
		&& ft_strchr(LABEL_CHARS, c))
	{
		++token->len;
		--cwr->pos;
	}
	if (token->type == TOKEN_ARG && c == '-')
	{
		++token->len;
		--cwr->pos;
		c = cwr->file[cwr->pos - 1];
	}
	if (token->type == TOKEN_ARG && (c == LABEL_CHAR || c == DIRECT_CHAR))
		parse_token_arg_qualifiers(cwr, token);
}

int		parse_token_label(t_cwr *cwr, t_token *token)
{
	char	c;

	token->type = TOKEN_LABEL;
	--cwr->pos;
	while (cwr->pos > 0 && (c = cwr->file[cwr->pos])
		&& ft_strchr(LABEL_CHARS, c))
	{
		++token->len;
		--cwr->pos;
	}
	skip_space(cwr, BACK);
	c = cwr->file[cwr->pos];
	if (!cwr_eol(c))
		return (cwr_error(cwr, "bad char before label: ", CWR_ERR_CHR));
	else
		++cwr->pos;
	return (EXIT_SUCCESS);
}

int		parse_token(t_cwr *cwr, t_token *token)
{
	char	c;
	int		ret;

	ret = EXIT_SUCCESS;
	c = cwr->file[cwr->pos];
	token->len = 1;
	if (c == SEPARATOR_CHAR)
		token->type = TOKEN_SEP;
	else if (c == LABEL_CHAR)
		ret = parse_token_label(cwr, token);
	else if (ft_strchr(LABEL_CHARS, c))
		parse_token_arg(cwr, token);
	else
		return (cwr_error(cwr, "bad char: ", CWR_ERR_CHR));
	token->content = cwr->cpy + cwr->pos;
	token->content_pos = cwr->pos;
	--cwr->pos;
	return (ret);
}

int		parse_line_tokens(t_cwr *cwr, t_line *line, t_token *token)
{
	int		ret;

	line->first_token = TOKEN_MAX;
	line->token_pos = TOKEN_MAX;
	while (line->token_pos >= 0)
	{
		--line->token_pos;
		--line->first_token;
		if ((ret = parse_token(cwr, &token[line->token_pos])) != EXIT_SUCCESS)
			return (ret);
		skip_space(cwr, BACK);
		if (cwr_eol(cwr->file[cwr->pos]))
		{
			return (EXIT_SUCCESS);
		}
	}
	return (cwr_error(cwr, "Line with too many arguments: ", CWR_ERR_LINE));
}
