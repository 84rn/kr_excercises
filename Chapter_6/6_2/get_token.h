
enum token_type
{
	EMPTY,
	VARIABLE,
	POINTER,
	COMMENT,
	MULTI_COMMENT,
	STRING,
	FUNCTION,
	PREPROCESSOR,
	CHARACTER
};

struct s_token
{
	char *value;
	token_type type;
};

struct s_token * new_token();
void free_token(struct s_token *t);
char * token_type_as_string(struct s_token *p);
struct s_token * get_token();