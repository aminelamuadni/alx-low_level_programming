/**
 * cap_string - Capitalizes all words of a string
 * @s: The string to change
 *
 * Return: A pointer to the changed string
 */
char *cap_string(char *s)
{
    int i = 0;
    int new_word = 1;

    while (s[i])
    {
        /* Check for separators */
        if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == ',' ||
            s[i] == ';' || s[i] == '.' || s[i] == '!' || s[i] == '?' ||
            s[i] == '"' || s[i] == '(' || s[i] == ')' || s[i] == '{' ||
            s[i] == '}')
        {
            new_word = 1;
        }
        /* If it's a new word, capitalize the first letter */
        else if (new_word && s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] -= 'a' - 'A';
            new_word = 0;
        }
        /* If it's not a new word and it's an uppercase letter, make it lowercase */
        else if (!new_word && s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] += 'a' - 'A';
        }
        else
        {
            new_word = 0;
        }

        i++;
    }

    return (s);
}
