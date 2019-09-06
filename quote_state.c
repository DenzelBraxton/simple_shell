#include "quote.h"

/**
 * quote_state - get the state associated with a given character
 * @c: character
 *
 * Return: the state associated with c
 */
quote_state_t quote_state(char c)
{
	if (_isspace(c))
		return (NONE);
	if (c == '"')
		return (DOUBLE);
	if (c == '\'')
		return (SINGLE);
	if (c == '\\')
		return (ESCAPE);
	return (WORD);
}


/**
 * quote_state_fn - get the function associated with a given state
 * @s: state
 *
 * Return: the state associated with c
 */
size_t (*quote_state_fn(quote_state_t s))(const char *, quote_state_t *)
{
	switch (s)
	{
	case NONE:
		return (_quote_state_none);
	case WORD:
		return (_quote_state_word);
	case DOUBLE:
		return (_quote_state_double);
	case SINGLE:
		return (_quote_state_single);
	case ESCAPE:
		return (_quote_state_escape);
	}
	return (NULL);
}


/**
 * quote_state_len - get the length of a given state
 * @s: state
 *
 * Return: the state associated with c
 */
size_t quote_state_len(const char *str, quote_state_t *state)
{
	if (state)
		return (quote_state_fn(*state)(str, state));

	return (quote_state_fn(quote_state(*str))(str, NULL));
}
