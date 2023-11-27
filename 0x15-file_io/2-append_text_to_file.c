#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: filename.
 * @text_content: added content.
 *
 * Return: 1 if the file exists. -1 if the fails does not exist
 * or if it fails.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int k;
	int nletter;
	int rwr;

	if (!filename)
		return (-1);

	k = open(filename, O_WRONLY | O_APPEND);

	if (k == -1)
		return (-1);

	if (text_content)
	{
		for (nletter = 0; text_content[nletter]; nletter++)
			;

		rwr = write(k, text_content, nletter);

		if (rwr == -1)
			return (-1);
	}

	close(k);

	return (1);
}
