#include "../cub3D.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char		*new;
	int			i;
	int			j;

	if (!s2)
		error("Error: Malloc failure!\n");
	if (!s1)
		s1 = strdup(""); // ft_strdup
	i = 0;
	j = 0;
	new = malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1)); // ft_strlen
	if (!new)
		error("Error: Malloc failure!\n");
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		new[i++] = s2[j++];
	new[i] = '\0';
	return (free(s1), new);
}

int	ft_strchr(char *s, int c)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}