
#include "pipex.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			s_len;

	if (s == NULL)
		return (0);
	s_len = ft_strlen(s);
	if (s_len < start)
		return (ft_strdup(""));
	if (start + len < s_len)
		str = (char *)malloc((len + 1) * sizeof(char));
	else
		str = (char *)malloc((s_len - start + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

static size_t	ft_word_count(char *str, char delim)
{
	int		is_previous_delim;
	int		i;
	size_t	word_cnt;

	is_previous_delim = 1;
	word_cnt = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == delim)
			is_previous_delim = 1;
		else if (is_previous_delim)
			word_cnt++;
		if (str[i] != delim)
			is_previous_delim = 0;
		i++;
	}
	return (word_cnt);
}

static char	**ft_free(size_t k, char **arr)
{
	while (k >= 0)
		free(arr[--k]);
	free(*arr);
	return (NULL);
}

static char	**ft_init_arr(char *s, char c, char **arr, size_t count)
{
	int		i;
	size_t	k;
	int		start_word;

	i = 0;
	k = 0;
	start_word = 0;
	while (k < count)
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			start_word = i;
		while (s[i] && s[i] != c)
			i++;
		arr[k] = ft_substr(s, start_word, (i - start_word));
		if (arr[k] == NULL)
			return (ft_free(k, arr));
		k++;
	}
	arr[k] = NULL;
	return (arr);
}

char	**ft_split(char *s, char c)
{
	size_t	num_of_words;
	char	**arr;

	if (!s)
		return (NULL);
	num_of_words = ft_word_count(s, c);
	arr = (char **) malloc(sizeof(char *) * (num_of_words + 1));
	if (!arr)
		return (NULL);
	arr = ft_init_arr(s, c, arr, num_of_words);
	return (arr);
}