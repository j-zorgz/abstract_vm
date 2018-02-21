#ifndef TOKEN_CLASS_H
# define TOKEN_CLASS_H

# include <string>
# include <iostream>

typedef enum {
	TOK_STRING,
	TOK_INTEGER,
	TOK_REAL,
	TOK_OPERATOR,
	TOK_SEP
} tokentype_t;

class Token {
public:
	Token(tokentype_t _type);
	Token(tokentype_t type, std::string content);
	Token(void);
	Token(Token const & src);
	~Token(void);

	Token & operator=(Token const & rhs);

	void setContent(std::string content);
	void setType(tokentype_t type);


private:
	tokentype_t _type;
	std::string _content;
};
#endif
