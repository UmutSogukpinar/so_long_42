#include "../../includes/game.h"

bool	is_file_extension_proper(char *file, char *extension)
{
	size_t	file_len;
	size_t	ext_len;

	if (!file || !extension)
		return (display_error_msg(INV_MAP_EXT, false));
	file_len = ft_strlen(file);
	ext_len = ft_strlen(extension);
	if (file_len <= ext_len || file[file_len - ext_len - 1] == SLASH)
		return (display_error_msg(INV_MAP_EXT, false));
	if (ft_strncmp(file + file_len - ext_len, extension, ext_len) != 0)
		return (display_error_msg(INV_MAP_EXT, false));
	return (true);
}
