#include <cstdio>

int main()
{
    FILE *input = fopen("input.txt", "r");
    if (input == NULL)
    {
        printf("Ошибка открытия файла\n");
        return 0;
    }
    enum States {
        out,
        inString,
        inChar,
        afterSlash,
        end,
        inStringAfterBackslash,
        inCharAfterBackslash,
        inCppComment,
        inCComment,
        inCCommentAfterAsterisk
    };
    States state = out;
    char c = EOF;
    while (true)
    {
        switch (state)
        {
            case out:
            {
                c = fgetc(input);
                switch (c)
                {
                    case '"':
                    {
                        state = inString;
                        break;
                    }
                    case '\'':
                    {
                        state = inChar;
                        break;
                    }
                    case '/':
                    {
                        state = afterSlash;
                        break;
                    }
                    case EOF:
                    {
                        state = end;
                        break;
                    }
                    default:
                    {
                        state = out;
                        break;
                    }
                }
                break;
            }
            case inString:
            {
                c = fgetc(input);
                switch (c)
                {
                    case '"':
                    {
                        state = out;
                        break;
                    }
                    case EOF:
                    {
                        state = end;
                        break;
                    }
                    case '\\':
                    {
                        state = inStringAfterBackslash;
                        break;
                    }
                    default:
                    {
                        state = inString;
                        break;
                    }
                }
                break;
            }
            case inChar:
            {
                c = fgetc(input);
                switch (c)
                {
                    case '\'':
                    {
                        state = out;
                        break;
                    }
                    case '\\':
                    {
                        state = inCharAfterBackslash;
                        break;
                    }
                    case EOF:
                    {
                        state = end;
                        break;
                    }
                    default:
                    {
                        state = inChar;
                        break;
                    }
                }
                break;
            }
            case afterSlash:
            {
                c = fgetc(input);
                switch (c)
                {
                    case '/':
                    {
                        printf("//");
                        state = inCppComment;
                        break;
                    }
                    case '*':
                    {
                        state = inCComment;
                        break;
                    }
                    case EOF:
                    {
                        state = end;
                        break;
                    }
                    default:
                    {
                        state = out;
                        break;
                    }
                }
                break;
            }
            case end:
            {
                fclose(input);
                return 0;
            }
            case inStringAfterBackslash:
            {
                c = fgetc(input);
                switch (c)
                {
                    case EOF:
                    {
                        state = end;
                        break;
                    }
                    default:
                    {
                        state = inString;
                        break;
                    }
                }
                break;
            }
            case inCharAfterBackslash:
            {
                c = fgetc(input);
                switch (c)
                {
                    case EOF:
                    {
                        state = end;
                        break;
                    }
                    default:
                    {
                        state = inChar;
                        break;
                    }
                }
                break;
            }
            case inCppComment:
            {
                c = fgetc(input);
                switch (c)
                {
                    case EOF:
                    {
                        state = end;
                        break;
                    }
                    case '\n':
                    {
                        putchar('\n');
                        state = out;
                        break;
                    }
                    default:
                    {
                        putchar(c);
                        state = inCppComment;
                        break;
                    }
                }
                break;
            }
            case inCComment:
            {
                c = fgetc(input);
                switch (c)
                {
                    case EOF:
                    {
                        state = end;
                        break;
                    }
                    case '*':
                    {
                        state = inCCommentAfterAsterisk;
                        break;
                    }
                    default:
                    {
                        state = inCComment;
                        break;
                    }
                }
                break;
            }
            case inCCommentAfterAsterisk:
            {
                c = fgetc(input);
                switch (c)
                {
                    case EOF:
                    {
                        state = end;
                        break;
                    }
                    case '/':
                    {
                        state = out;
                        break;
                    }
                    default:
                    {
                        state = inCComment;
                        break;
                    }
                }
                break;
            }
        }
    }
}

