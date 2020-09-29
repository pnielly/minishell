#include "utils.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *mem;

	mem = (unsigned char*)malloc(sizeof(size_t) * size);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}
