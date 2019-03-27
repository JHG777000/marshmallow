#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#ifdef _MSC_VER
#pragma optimize("", off)
#elif defined(__clang__)
#pragma clang optimize off
#elif defined(__GNUC__)
#pragma GCC optimize ("O0")
#endif

#define LANGUAGE_VERSION 9
#define STATE_COUNT 227
#define SYMBOL_COUNT 169
#define ALIAS_COUNT 0
#define TOKEN_COUNT 98
#define EXTERNAL_TOKEN_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 7

enum {
  sym__comment = 1,
  anon_sym_COMMA = 2,
  sym_readonly = 3,
  anon_sym_private = 4,
  anon_sym_protected = 5,
  anon_sym_publish = 6,
  anon_sym_end = 7,
  anon_sym_module = 8,
  anon_sym_function = 9,
  anon_sym_method = 10,
  anon_sym_if = 11,
  anon_sym_while = 12,
  anon_sym_switch = 13,
  anon_sym_case = 14,
  anon_sym_default = 15,
  anon_sym_DOT = 16,
  anon_sym_enum = 17,
  anon_sym_LPAREN = 18,
  anon_sym_RPAREN = 19,
  anon_sym_returns = 20,
  anon_sym_i8 = 21,
  anon_sym_i16 = 22,
  anon_sym_i32 = 23,
  anon_sym_i64 = 24,
  anon_sym_u8 = 25,
  anon_sym_u16 = 26,
  anon_sym_u32 = 27,
  anon_sym_u64 = 28,
  anon_sym_f32 = 29,
  anon_sym_f64 = 30,
  anon_sym_s8 = 31,
  anon_sym_s16 = 32,
  anon_sym_s32 = 33,
  anon_sym_STAR = 34,
  anon_sym_LBRACK = 35,
  anon_sym_RBRACK = 36,
  sym_is_declare = 37,
  sym_is_external = 38,
  anon_sym_goto = 39,
  anon_sym_section = 40,
  anon_sym_COLON_EQ = 41,
  anon_sym_return = 42,
  anon_sym_DASH = 43,
  anon_sym_AMP = 44,
  anon_sym_BANG = 45,
  anon_sym_TILDE = 46,
  anon_sym_PLUS = 47,
  anon_sym_SLASH = 48,
  anon_sym_PERCENT = 49,
  anon_sym_PIPE = 50,
  anon_sym_CARET = 51,
  anon_sym_GT = 52,
  anon_sym_LT = 53,
  anon_sym_GT_EQ = 54,
  anon_sym_LT_EQ = 55,
  anon_sym_BANG_EQ = 56,
  anon_sym_EQ_EQ = 57,
  anon_sym_AMP_AMP = 58,
  anon_sym_PIPE_PIPE = 59,
  anon_sym_GT_GT = 60,
  anon_sym_LT_LT = 61,
  anon_sym_PLUS_EQ = 62,
  anon_sym_DASH_EQ = 63,
  anon_sym_STAR_EQ = 64,
  anon_sym_SLASH_EQ = 65,
  anon_sym_PERCENT_EQ = 66,
  anon_sym_AMP_EQ = 67,
  anon_sym_PIPE_EQ = 68,
  anon_sym_CARET_EQ = 69,
  anon_sym_GT_GT_EQ = 70,
  anon_sym_LT_LT_EQ = 71,
  anon_sym_PLUS_PLUS = 72,
  anon_sym_DASH_DASH = 73,
  anon_sym_LBRACE = 74,
  anon_sym_RBRACE = 75,
  sym_null = 76,
  sym_identifier = 77,
  anon_sym_DQUOTE = 78,
  aux_sym_string_token1 = 79,
  anon_sym_SQUOTE = 80,
  aux_sym_character_token1 = 81,
  anon_sym_BSLASH_BSLASH = 82,
  anon_sym_BSLASH0 = 83,
  anon_sym_BSLASHa = 84,
  anon_sym_BSLASHb = 85,
  anon_sym_BSLASHf = 86,
  anon_sym_BSLASHn = 87,
  anon_sym_BSLASHr = 88,
  anon_sym_BSLASHt = 89,
  anon_sym_BSLASHv = 90,
  sym_oct = 91,
  sym_integer = 92,
  sym_long = 93,
  sym_float = 94,
  sym_double = 95,
  sym_hex = 96,
  sym_binary = 97,
  sym_source_file = 98,
  sym__comma_list_variables = 99,
  sym__comma_list_assignment_or_collection_or_value = 100,
  sym__comma_list_types = 101,
  sym_access_control = 102,
  sym_end_module = 103,
  sym_end_function = 104,
  sym_end_method = 105,
  sym__end_function = 106,
  sym_end_if = 107,
  sym_end_while = 108,
  sym_end_switch = 109,
  sym_end_case = 110,
  sym_end_default = 111,
  sym_module_definition = 112,
  sym__definitions = 113,
  sym__enum_element = 114,
  sym_enum_definition = 115,
  sym_is_function = 116,
  sym_is_method = 117,
  sym_function_signature = 118,
  sym_function_definition = 119,
  sym_variable_definition = 120,
  sym_parameter_list = 121,
  sym_return_list = 122,
  sym_type = 123,
  sym__base_type = 124,
  sym_primitive_type = 125,
  sym_pointer = 126,
  sym_array = 127,
  sym_declaration_definition = 128,
  sym__statement = 129,
  sym__control_flow_statement = 130,
  sym_goto_statement = 131,
  sym_section_statement = 132,
  sym_single_line_if_statement = 133,
  sym_if_statement = 134,
  sym_while_statement = 135,
  sym_switch_statement = 136,
  sym_case_statement = 137,
  sym_default_statement = 138,
  sym__variable_statement = 139,
  sym_static_assignment = 140,
  sym_expression_statement = 141,
  sym_return_statement = 142,
  sym_group_expression = 143,
  sym_assignment_expression = 144,
  sym_unary_op = 145,
  sym_binary_op = 146,
  sym_assignment_op = 147,
  sym_assignment_post_op = 148,
  sym__assignment_or_collection_or_value = 149,
  sym__collection_or_value = 150,
  sym_collection = 151,
  sym__value = 152,
  sym__literal = 153,
  sym_string = 154,
  sym_character = 155,
  sym__escape_sequence = 156,
  sym__number = 157,
  aux_sym_source_file_repeat1 = 158,
  aux_sym__comma_list_variables_repeat1 = 159,
  aux_sym__comma_list_assignment_or_collection_or_value_repeat1 = 160,
  aux_sym__comma_list_types_repeat1 = 161,
  aux_sym_module_definition_repeat1 = 162,
  aux_sym_enum_definition_repeat1 = 163,
  aux_sym_function_definition_repeat1 = 164,
  aux_sym_type_repeat1 = 165,
  aux_sym_type_repeat2 = 166,
  aux_sym_switch_statement_repeat1 = 167,
  aux_sym_string_repeat1 = 168,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym__comment] = "_comment",
  [anon_sym_COMMA] = ",",
  [sym_readonly] = "readonly",
  [anon_sym_private] = "private",
  [anon_sym_protected] = "protected",
  [anon_sym_publish] = "publish",
  [anon_sym_end] = "end",
  [anon_sym_module] = "module",
  [anon_sym_function] = "function",
  [anon_sym_method] = "method",
  [anon_sym_if] = "if",
  [anon_sym_while] = "while",
  [anon_sym_switch] = "switch",
  [anon_sym_case] = "case",
  [anon_sym_default] = "default",
  [anon_sym_DOT] = ".",
  [anon_sym_enum] = "enum",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_returns] = "returns",
  [anon_sym_i8] = "i8",
  [anon_sym_i16] = "i16",
  [anon_sym_i32] = "i32",
  [anon_sym_i64] = "i64",
  [anon_sym_u8] = "u8",
  [anon_sym_u16] = "u16",
  [anon_sym_u32] = "u32",
  [anon_sym_u64] = "u64",
  [anon_sym_f32] = "f32",
  [anon_sym_f64] = "f64",
  [anon_sym_s8] = "s8",
  [anon_sym_s16] = "s16",
  [anon_sym_s32] = "s32",
  [anon_sym_STAR] = "*",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [sym_is_declare] = "is_declare",
  [sym_is_external] = "is_external",
  [anon_sym_goto] = "goto",
  [anon_sym_section] = "section",
  [anon_sym_COLON_EQ] = ":=",
  [anon_sym_return] = "return",
  [anon_sym_DASH] = "-",
  [anon_sym_AMP] = "&",
  [anon_sym_BANG] = "!",
  [anon_sym_TILDE] = "~",
  [anon_sym_PLUS] = "+",
  [anon_sym_SLASH] = "/",
  [anon_sym_PERCENT] = "%",
  [anon_sym_PIPE] = "|",
  [anon_sym_CARET] = "^",
  [anon_sym_GT] = ">",
  [anon_sym_LT] = "<",
  [anon_sym_GT_EQ] = ">=",
  [anon_sym_LT_EQ] = "<=",
  [anon_sym_BANG_EQ] = "!=",
  [anon_sym_EQ_EQ] = "==",
  [anon_sym_AMP_AMP] = "&&",
  [anon_sym_PIPE_PIPE] = "||",
  [anon_sym_GT_GT] = ">>",
  [anon_sym_LT_LT] = "<<",
  [anon_sym_PLUS_EQ] = "+=",
  [anon_sym_DASH_EQ] = "-=",
  [anon_sym_STAR_EQ] = "*=",
  [anon_sym_SLASH_EQ] = "/=",
  [anon_sym_PERCENT_EQ] = "%=",
  [anon_sym_AMP_EQ] = "&=",
  [anon_sym_PIPE_EQ] = "|=",
  [anon_sym_CARET_EQ] = "^=",
  [anon_sym_GT_GT_EQ] = ">>=",
  [anon_sym_LT_LT_EQ] = "<<=",
  [anon_sym_PLUS_PLUS] = "++",
  [anon_sym_DASH_DASH] = "--",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [sym_null] = "null",
  [sym_identifier] = "identifier",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_string_token1] = "string_token1",
  [anon_sym_SQUOTE] = "'",
  [aux_sym_character_token1] = "character_token1",
  [anon_sym_BSLASH_BSLASH] = "\\\\",
  [anon_sym_BSLASH0] = "\\0",
  [anon_sym_BSLASHa] = "\\a",
  [anon_sym_BSLASHb] = "\\b",
  [anon_sym_BSLASHf] = "\\f",
  [anon_sym_BSLASHn] = "\\n",
  [anon_sym_BSLASHr] = "\\r",
  [anon_sym_BSLASHt] = "\\t",
  [anon_sym_BSLASHv] = "\\v",
  [sym_oct] = "oct",
  [sym_integer] = "integer",
  [sym_long] = "long",
  [sym_float] = "float",
  [sym_double] = "double",
  [sym_hex] = "hex",
  [sym_binary] = "binary",
  [sym_source_file] = "source_file",
  [sym__comma_list_variables] = "_comma_list_variables",
  [sym__comma_list_assignment_or_collection_or_value] = "_comma_list_assignment_or_collection_or_value",
  [sym__comma_list_types] = "_comma_list_types",
  [sym_access_control] = "access_control",
  [sym_end_module] = "end_module",
  [sym_end_function] = "end_function",
  [sym_end_method] = "end_method",
  [sym__end_function] = "_end_function",
  [sym_end_if] = "end_if",
  [sym_end_while] = "end_while",
  [sym_end_switch] = "end_switch",
  [sym_end_case] = "end_case",
  [sym_end_default] = "end_default",
  [sym_module_definition] = "module_definition",
  [sym__definitions] = "_definitions",
  [sym__enum_element] = "_enum_element",
  [sym_enum_definition] = "enum_definition",
  [sym_is_function] = "is_function",
  [sym_is_method] = "is_method",
  [sym_function_signature] = "function_signature",
  [sym_function_definition] = "function_definition",
  [sym_variable_definition] = "variable_definition",
  [sym_parameter_list] = "parameter_list",
  [sym_return_list] = "return_list",
  [sym_type] = "type",
  [sym__base_type] = "_base_type",
  [sym_primitive_type] = "primitive_type",
  [sym_pointer] = "pointer",
  [sym_array] = "array",
  [sym_declaration_definition] = "declaration_definition",
  [sym__statement] = "_statement",
  [sym__control_flow_statement] = "_control_flow_statement",
  [sym_goto_statement] = "goto_statement",
  [sym_section_statement] = "section_statement",
  [sym_single_line_if_statement] = "single_line_if_statement",
  [sym_if_statement] = "if_statement",
  [sym_while_statement] = "while_statement",
  [sym_switch_statement] = "switch_statement",
  [sym_case_statement] = "case_statement",
  [sym_default_statement] = "default_statement",
  [sym__variable_statement] = "_variable_statement",
  [sym_static_assignment] = "static_assignment",
  [sym_expression_statement] = "expression_statement",
  [sym_return_statement] = "return_statement",
  [sym_group_expression] = "group_expression",
  [sym_assignment_expression] = "assignment_expression",
  [sym_unary_op] = "unary_op",
  [sym_binary_op] = "binary_op",
  [sym_assignment_op] = "assignment_op",
  [sym_assignment_post_op] = "assignment_post_op",
  [sym__assignment_or_collection_or_value] = "_assignment_or_collection_or_value",
  [sym__collection_or_value] = "_collection_or_value",
  [sym_collection] = "collection",
  [sym__value] = "_value",
  [sym__literal] = "_literal",
  [sym_string] = "string",
  [sym_character] = "character",
  [sym__escape_sequence] = "_escape_sequence",
  [sym__number] = "_number",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym__comma_list_variables_repeat1] = "_comma_list_variables_repeat1",
  [aux_sym__comma_list_assignment_or_collection_or_value_repeat1] = "_comma_list_assignment_or_collection_or_value_repeat1",
  [aux_sym__comma_list_types_repeat1] = "_comma_list_types_repeat1",
  [aux_sym_module_definition_repeat1] = "module_definition_repeat1",
  [aux_sym_enum_definition_repeat1] = "enum_definition_repeat1",
  [aux_sym_function_definition_repeat1] = "function_definition_repeat1",
  [aux_sym_type_repeat1] = "type_repeat1",
  [aux_sym_type_repeat2] = "type_repeat2",
  [aux_sym_switch_statement_repeat1] = "switch_statement_repeat1",
  [aux_sym_string_repeat1] = "string_repeat1",
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym__comment] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [sym_readonly] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_private] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_protected] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_publish] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_end] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_module] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_function] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_method] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_if] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_while] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_switch] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_case] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_default] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_enum] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_returns] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_i8] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_i16] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_i32] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_i64] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u8] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u16] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u32] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u64] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_f32] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_f64] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_s8] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_s16] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_s32] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [sym_is_declare] = {
    .visible = true,
    .named = true,
  },
  [sym_is_external] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_goto] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_section] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_return] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_TILDE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PERCENT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CARET] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP_AMP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PERCENT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CARET_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_GT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_LT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [sym_null] = {
    .visible = true,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_character_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_BSLASH_BSLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASH0] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASHa] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASHb] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASHf] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASHn] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASHr] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASHt] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASHv] = {
    .visible = true,
    .named = false,
  },
  [sym_oct] = {
    .visible = true,
    .named = true,
  },
  [sym_integer] = {
    .visible = true,
    .named = true,
  },
  [sym_long] = {
    .visible = true,
    .named = true,
  },
  [sym_float] = {
    .visible = true,
    .named = true,
  },
  [sym_double] = {
    .visible = true,
    .named = true,
  },
  [sym_hex] = {
    .visible = true,
    .named = true,
  },
  [sym_binary] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__comma_list_variables] = {
    .visible = false,
    .named = true,
  },
  [sym__comma_list_assignment_or_collection_or_value] = {
    .visible = false,
    .named = true,
  },
  [sym__comma_list_types] = {
    .visible = false,
    .named = true,
  },
  [sym_access_control] = {
    .visible = true,
    .named = true,
  },
  [sym_end_module] = {
    .visible = true,
    .named = true,
  },
  [sym_end_function] = {
    .visible = true,
    .named = true,
  },
  [sym_end_method] = {
    .visible = true,
    .named = true,
  },
  [sym__end_function] = {
    .visible = false,
    .named = true,
  },
  [sym_end_if] = {
    .visible = true,
    .named = true,
  },
  [sym_end_while] = {
    .visible = true,
    .named = true,
  },
  [sym_end_switch] = {
    .visible = true,
    .named = true,
  },
  [sym_end_case] = {
    .visible = true,
    .named = true,
  },
  [sym_end_default] = {
    .visible = true,
    .named = true,
  },
  [sym_module_definition] = {
    .visible = true,
    .named = true,
  },
  [sym__definitions] = {
    .visible = false,
    .named = true,
  },
  [sym__enum_element] = {
    .visible = false,
    .named = true,
  },
  [sym_enum_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_is_function] = {
    .visible = true,
    .named = true,
  },
  [sym_is_method] = {
    .visible = true,
    .named = true,
  },
  [sym_function_signature] = {
    .visible = true,
    .named = true,
  },
  [sym_function_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_variable_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_parameter_list] = {
    .visible = true,
    .named = true,
  },
  [sym_return_list] = {
    .visible = true,
    .named = true,
  },
  [sym_type] = {
    .visible = true,
    .named = true,
  },
  [sym__base_type] = {
    .visible = false,
    .named = true,
  },
  [sym_primitive_type] = {
    .visible = true,
    .named = true,
  },
  [sym_pointer] = {
    .visible = true,
    .named = true,
  },
  [sym_array] = {
    .visible = true,
    .named = true,
  },
  [sym_declaration_definition] = {
    .visible = true,
    .named = true,
  },
  [sym__statement] = {
    .visible = false,
    .named = true,
  },
  [sym__control_flow_statement] = {
    .visible = false,
    .named = true,
  },
  [sym_goto_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_section_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_single_line_if_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_if_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_while_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_switch_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_case_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_default_statement] = {
    .visible = true,
    .named = true,
  },
  [sym__variable_statement] = {
    .visible = false,
    .named = true,
  },
  [sym_static_assignment] = {
    .visible = true,
    .named = true,
  },
  [sym_expression_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_return_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_group_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_assignment_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_unary_op] = {
    .visible = true,
    .named = true,
  },
  [sym_binary_op] = {
    .visible = true,
    .named = true,
  },
  [sym_assignment_op] = {
    .visible = true,
    .named = true,
  },
  [sym_assignment_post_op] = {
    .visible = true,
    .named = true,
  },
  [sym__assignment_or_collection_or_value] = {
    .visible = false,
    .named = true,
  },
  [sym__collection_or_value] = {
    .visible = false,
    .named = true,
  },
  [sym_collection] = {
    .visible = true,
    .named = true,
  },
  [sym__value] = {
    .visible = false,
    .named = true,
  },
  [sym__literal] = {
    .visible = false,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [sym_character] = {
    .visible = true,
    .named = true,
  },
  [sym__escape_sequence] = {
    .visible = false,
    .named = true,
  },
  [sym__number] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__comma_list_variables_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__comma_list_assignment_or_collection_or_value_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__comma_list_types_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_module_definition_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_enum_definition_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_function_definition_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_type_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_type_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_switch_statement_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  switch (state) {
    case 0:
      if (lookahead == 0)
        ADVANCE(1);
      if (lookahead == '!')
        ADVANCE(2);
      if (lookahead == '"')
        ADVANCE(3);
      if (lookahead == '%')
        ADVANCE(4);
      if (lookahead == '&')
        ADVANCE(5);
      if (lookahead == '\'')
        ADVANCE(6);
      if (lookahead == '(')
        ADVANCE(7);
      if (lookahead == ')')
        ADVANCE(8);
      if (lookahead == '*')
        ADVANCE(9);
      if (lookahead == '+')
        ADVANCE(10);
      if (lookahead == ',')
        ADVANCE(11);
      if (lookahead == '-')
        ADVANCE(12);
      if (lookahead == '.')
        ADVANCE(13);
      if (lookahead == '/')
        ADVANCE(14);
      if (lookahead == '0')
        ADVANCE(15);
      if (lookahead == ':')
        ADVANCE(16);
      if (lookahead == '<')
        ADVANCE(17);
      if (lookahead == '=')
        ADVANCE(18);
      if (lookahead == '>')
        ADVANCE(19);
      if (lookahead == '[')
        ADVANCE(20);
      if (lookahead == '\\')
        ADVANCE(21);
      if (lookahead == ']')
        ADVANCE(22);
      if (lookahead == '^')
        ADVANCE(23);
      if (lookahead == 'c')
        ADVANCE(24);
      if (lookahead == 'd')
        ADVANCE(25);
      if (lookahead == 'e')
        ADVANCE(26);
      if (lookahead == 'f')
        ADVANCE(27);
      if (lookahead == 'g')
        ADVANCE(28);
      if (lookahead == 'i')
        ADVANCE(29);
      if (lookahead == 'm')
        ADVANCE(30);
      if (lookahead == 'n')
        ADVANCE(31);
      if (lookahead == 'p')
        ADVANCE(32);
      if (lookahead == 'r')
        ADVANCE(33);
      if (lookahead == 's')
        ADVANCE(34);
      if (lookahead == 'u')
        ADVANCE(35);
      if (lookahead == 'w')
        ADVANCE(36);
      if (lookahead == '{')
        ADVANCE(37);
      if (lookahead == '|')
        ADVANCE(38);
      if (lookahead == '}')
        ADVANCE(39);
      if (lookahead == '~')
        ADVANCE(40);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(0);
      if (('1' <= lookahead && lookahead <= '9'))
        ADVANCE(41);
      if (lookahead != 0)
        ADVANCE(42);
      END_STATE();
    case 1:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 2:
      ACCEPT_TOKEN(anon_sym_BANG);
      if (lookahead == '=')
        ADVANCE(43);
      END_STATE();
    case 3:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 4:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '=')
        ADVANCE(44);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(anon_sym_AMP);
      if (lookahead == '&')
        ADVANCE(45);
      if (lookahead == '=')
        ADVANCE(46);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '=')
        ADVANCE(47);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(anon_sym_PLUS);
      if (lookahead == '+')
        ADVANCE(48);
      if (lookahead == '=')
        ADVANCE(49);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '+')
        ADVANCE(50);
      if (lookahead == '-')
        ADVANCE(51);
      if (lookahead == '=')
        ADVANCE(52);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_DOT);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(53);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '/')
        ADVANCE(54);
      if (lookahead == '=')
        ADVANCE(55);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == '.')
        ADVANCE(53);
      if (lookahead == 'b')
        ADVANCE(56);
      if (lookahead == 'f')
        ADVANCE(57);
      if (lookahead == 'l')
        ADVANCE(58);
      if (lookahead == 'x')
        ADVANCE(59);
      if (lookahead == '8' ||
          lookahead == '9')
        ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '7'))
        ADVANCE(61);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == '=')
        ADVANCE(62);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '<')
        ADVANCE(63);
      if (lookahead == '=')
        ADVANCE(64);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == '=')
        ADVANCE(65);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=')
        ADVANCE(66);
      if (lookahead == '>')
        ADVANCE(67);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == '0')
        ADVANCE(68);
      if (lookahead == '\\')
        ADVANCE(69);
      if (lookahead == 'a')
        ADVANCE(70);
      if (lookahead == 'b')
        ADVANCE(71);
      if (lookahead == 'f')
        ADVANCE(72);
      if (lookahead == 'n')
        ADVANCE(73);
      if (lookahead == 'r')
        ADVANCE(74);
      if (lookahead == 't')
        ADVANCE(75);
      if (lookahead == 'v')
        ADVANCE(76);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_CARET);
      if (lookahead == '=')
        ADVANCE(77);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == 'a')
        ADVANCE(78);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == 'e')
        ADVANCE(79);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == 'n')
        ADVANCE(80);
      if (lookahead == 'x')
        ADVANCE(81);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == '3')
        ADVANCE(82);
      if (lookahead == '6')
        ADVANCE(83);
      if (lookahead == 'u')
        ADVANCE(84);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == 'o')
        ADVANCE(85);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == '1')
        ADVANCE(86);
      if (lookahead == '3')
        ADVANCE(87);
      if (lookahead == '6')
        ADVANCE(88);
      if (lookahead == '8')
        ADVANCE(89);
      if (lookahead == 'f')
        ADVANCE(90);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == 'e')
        ADVANCE(91);
      if (lookahead == 'o')
        ADVANCE(92);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == 'u')
        ADVANCE(93);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == 'r')
        ADVANCE(94);
      if (lookahead == 'u')
        ADVANCE(95);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == 'e')
        ADVANCE(96);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == '1')
        ADVANCE(97);
      if (lookahead == '3')
        ADVANCE(98);
      if (lookahead == '8')
        ADVANCE(99);
      if (lookahead == 'e')
        ADVANCE(100);
      if (lookahead == 'w')
        ADVANCE(101);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == '1')
        ADVANCE(102);
      if (lookahead == '3')
        ADVANCE(103);
      if (lookahead == '6')
        ADVANCE(104);
      if (lookahead == '8')
        ADVANCE(105);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == 'h')
        ADVANCE(106);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '=')
        ADVANCE(107);
      if (lookahead == '|')
        ADVANCE(108);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_TILDE);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == '.')
        ADVANCE(53);
      if (lookahead == 'f')
        ADVANCE(57);
      if (lookahead == 'l')
        ADVANCE(58);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(60);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(aux_sym_character_token1);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_BANG_EQ);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_PERCENT_EQ);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_AMP_AMP);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_AMP_EQ);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_STAR_EQ);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_PLUS_PLUS);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_PLUS_EQ);
      END_STATE();
    case 50:
      if (lookahead == '+')
        ADVANCE(109);
      if (lookahead != 0)
        ADVANCE(50);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_DASH_DASH);
      if (lookahead == '-')
        ADVANCE(54);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_DASH_EQ);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_double);
      if (lookahead == 'f')
        ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(53);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym__comment);
      if (lookahead != 0 &&
          lookahead != '\n')
        ADVANCE(54);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_SLASH_EQ);
      END_STATE();
    case 56:
      if (lookahead == '0' ||
          lookahead == '1')
        ADVANCE(110);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_float);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_long);
      END_STATE();
    case 59:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'f'))
        ADVANCE(111);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.')
        ADVANCE(53);
      if (lookahead == 'f')
        ADVANCE(57);
      if (lookahead == 'l')
        ADVANCE(58);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(60);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_oct);
      if (lookahead == '.')
        ADVANCE(53);
      if (lookahead == 'f')
        ADVANCE(57);
      if (lookahead == 'l')
        ADVANCE(58);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(60);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_COLON_EQ);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_LT_LT);
      if (lookahead == '=')
        ADVANCE(112);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_GT_GT);
      if (lookahead == '=')
        ADVANCE(113);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_BSLASH0);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_BSLASH_BSLASH);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_BSLASHa);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_BSLASHb);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_BSLASHf);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_BSLASHn);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_BSLASHr);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_BSLASHt);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_BSLASHv);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_CARET_EQ);
      END_STATE();
    case 78:
      if (lookahead == 's')
        ADVANCE(114);
      END_STATE();
    case 79:
      if (lookahead == 'c')
        ADVANCE(115);
      if (lookahead == 'f')
        ADVANCE(116);
      END_STATE();
    case 80:
      if (lookahead == 'd')
        ADVANCE(117);
      if (lookahead == 'u')
        ADVANCE(118);
      END_STATE();
    case 81:
      if (lookahead == 't')
        ADVANCE(119);
      END_STATE();
    case 82:
      if (lookahead == '2')
        ADVANCE(120);
      END_STATE();
    case 83:
      if (lookahead == '4')
        ADVANCE(121);
      END_STATE();
    case 84:
      if (lookahead == 'n')
        ADVANCE(122);
      END_STATE();
    case 85:
      if (lookahead == 't')
        ADVANCE(123);
      END_STATE();
    case 86:
      if (lookahead == '6')
        ADVANCE(124);
      END_STATE();
    case 87:
      if (lookahead == '2')
        ADVANCE(125);
      END_STATE();
    case 88:
      if (lookahead == '4')
        ADVANCE(126);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_i8);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_if);
      END_STATE();
    case 91:
      if (lookahead == 't')
        ADVANCE(127);
      END_STATE();
    case 92:
      if (lookahead == 'd')
        ADVANCE(128);
      END_STATE();
    case 93:
      if (lookahead == 'l')
        ADVANCE(129);
      END_STATE();
    case 94:
      if (lookahead == 'i')
        ADVANCE(130);
      if (lookahead == 'o')
        ADVANCE(131);
      END_STATE();
    case 95:
      if (lookahead == 'b')
        ADVANCE(132);
      END_STATE();
    case 96:
      if (lookahead == 'a')
        ADVANCE(133);
      if (lookahead == 't')
        ADVANCE(134);
      END_STATE();
    case 97:
      if (lookahead == '6')
        ADVANCE(135);
      END_STATE();
    case 98:
      if (lookahead == '2')
        ADVANCE(136);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_s8);
      END_STATE();
    case 100:
      if (lookahead == 'c')
        ADVANCE(137);
      END_STATE();
    case 101:
      if (lookahead == 'i')
        ADVANCE(138);
      END_STATE();
    case 102:
      if (lookahead == '6')
        ADVANCE(139);
      END_STATE();
    case 103:
      if (lookahead == '2')
        ADVANCE(140);
      END_STATE();
    case 104:
      if (lookahead == '4')
        ADVANCE(141);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_u8);
      END_STATE();
    case 106:
      if (lookahead == 'i')
        ADVANCE(142);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(anon_sym_PIPE_EQ);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(anon_sym_PIPE_PIPE);
      END_STATE();
    case 109:
      if (lookahead == '+')
        ADVANCE(109);
      if (lookahead == '-')
        ADVANCE(143);
      if (lookahead != 0)
        ADVANCE(50);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(sym_binary);
      if (lookahead == '0' ||
          lookahead == '1')
        ADVANCE(110);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(sym_hex);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'f'))
        ADVANCE(111);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(anon_sym_LT_LT_EQ);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_GT_GT_EQ);
      END_STATE();
    case 114:
      if (lookahead == 'e')
        ADVANCE(144);
      END_STATE();
    case 115:
      if (lookahead == 'l')
        ADVANCE(145);
      END_STATE();
    case 116:
      if (lookahead == 'a')
        ADVANCE(146);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_end);
      END_STATE();
    case 118:
      if (lookahead == 'm')
        ADVANCE(147);
      END_STATE();
    case 119:
      if (lookahead == 'e')
        ADVANCE(148);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_f32);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_f64);
      END_STATE();
    case 122:
      if (lookahead == 'c')
        ADVANCE(149);
      END_STATE();
    case 123:
      if (lookahead == 'o')
        ADVANCE(150);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_i16);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(anon_sym_i32);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_i64);
      END_STATE();
    case 127:
      if (lookahead == 'h')
        ADVANCE(151);
      END_STATE();
    case 128:
      if (lookahead == 'u')
        ADVANCE(152);
      END_STATE();
    case 129:
      if (lookahead == 'l')
        ADVANCE(153);
      END_STATE();
    case 130:
      if (lookahead == 'v')
        ADVANCE(154);
      END_STATE();
    case 131:
      if (lookahead == 't')
        ADVANCE(155);
      END_STATE();
    case 132:
      if (lookahead == 'l')
        ADVANCE(156);
      END_STATE();
    case 133:
      if (lookahead == 'd')
        ADVANCE(157);
      END_STATE();
    case 134:
      if (lookahead == 'u')
        ADVANCE(158);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(anon_sym_s16);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(anon_sym_s32);
      END_STATE();
    case 137:
      if (lookahead == 't')
        ADVANCE(159);
      END_STATE();
    case 138:
      if (lookahead == 't')
        ADVANCE(160);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(anon_sym_u16);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(anon_sym_u32);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(anon_sym_u64);
      END_STATE();
    case 142:
      if (lookahead == 'l')
        ADVANCE(161);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(sym__comment);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(anon_sym_case);
      END_STATE();
    case 145:
      if (lookahead == 'a')
        ADVANCE(162);
      END_STATE();
    case 146:
      if (lookahead == 'u')
        ADVANCE(163);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(anon_sym_enum);
      END_STATE();
    case 148:
      if (lookahead == 'r')
        ADVANCE(164);
      END_STATE();
    case 149:
      if (lookahead == 't')
        ADVANCE(165);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(anon_sym_goto);
      END_STATE();
    case 151:
      if (lookahead == 'o')
        ADVANCE(166);
      END_STATE();
    case 152:
      if (lookahead == 'l')
        ADVANCE(167);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(sym_null);
      END_STATE();
    case 154:
      if (lookahead == 'a')
        ADVANCE(168);
      END_STATE();
    case 155:
      if (lookahead == 'e')
        ADVANCE(169);
      END_STATE();
    case 156:
      if (lookahead == 'i')
        ADVANCE(170);
      END_STATE();
    case 157:
      if (lookahead == 'o')
        ADVANCE(171);
      END_STATE();
    case 158:
      if (lookahead == 'r')
        ADVANCE(172);
      END_STATE();
    case 159:
      if (lookahead == 'i')
        ADVANCE(173);
      END_STATE();
    case 160:
      if (lookahead == 'c')
        ADVANCE(174);
      END_STATE();
    case 161:
      if (lookahead == 'e')
        ADVANCE(175);
      END_STATE();
    case 162:
      if (lookahead == 'r')
        ADVANCE(176);
      END_STATE();
    case 163:
      if (lookahead == 'l')
        ADVANCE(177);
      END_STATE();
    case 164:
      if (lookahead == 'n')
        ADVANCE(178);
      END_STATE();
    case 165:
      if (lookahead == 'i')
        ADVANCE(179);
      END_STATE();
    case 166:
      if (lookahead == 'd')
        ADVANCE(180);
      END_STATE();
    case 167:
      if (lookahead == 'e')
        ADVANCE(181);
      END_STATE();
    case 168:
      if (lookahead == 't')
        ADVANCE(182);
      END_STATE();
    case 169:
      if (lookahead == 'c')
        ADVANCE(183);
      END_STATE();
    case 170:
      if (lookahead == 's')
        ADVANCE(184);
      END_STATE();
    case 171:
      if (lookahead == 'n')
        ADVANCE(185);
      END_STATE();
    case 172:
      if (lookahead == 'n')
        ADVANCE(186);
      END_STATE();
    case 173:
      if (lookahead == 'o')
        ADVANCE(187);
      END_STATE();
    case 174:
      if (lookahead == 'h')
        ADVANCE(188);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(anon_sym_while);
      END_STATE();
    case 176:
      if (lookahead == 'e')
        ADVANCE(189);
      END_STATE();
    case 177:
      if (lookahead == 't')
        ADVANCE(190);
      END_STATE();
    case 178:
      if (lookahead == 'a')
        ADVANCE(191);
      END_STATE();
    case 179:
      if (lookahead == 'o')
        ADVANCE(192);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(anon_sym_method);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(anon_sym_module);
      END_STATE();
    case 182:
      if (lookahead == 'e')
        ADVANCE(193);
      END_STATE();
    case 183:
      if (lookahead == 't')
        ADVANCE(194);
      END_STATE();
    case 184:
      if (lookahead == 'h')
        ADVANCE(195);
      END_STATE();
    case 185:
      if (lookahead == 'l')
        ADVANCE(196);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(anon_sym_return);
      END_STATE();
    case 187:
      if (lookahead == 'n')
        ADVANCE(197);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(anon_sym_switch);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(sym_is_declare);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(anon_sym_default);
      END_STATE();
    case 191:
      if (lookahead == 'l')
        ADVANCE(198);
      END_STATE();
    case 192:
      if (lookahead == 'n')
        ADVANCE(199);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(anon_sym_private);
      END_STATE();
    case 194:
      if (lookahead == 'e')
        ADVANCE(200);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(anon_sym_publish);
      END_STATE();
    case 196:
      if (lookahead == 'y')
        ADVANCE(201);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(anon_sym_section);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(sym_is_external);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(anon_sym_function);
      END_STATE();
    case 200:
      if (lookahead == 'd')
        ADVANCE(202);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(sym_readonly);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(anon_sym_protected);
      END_STATE();
    case 203:
      if (lookahead == 0)
        ADVANCE(1);
      if (lookahead == '-')
        ADVANCE(204);
      if (lookahead == '/')
        ADVANCE(205);
      if (lookahead == 'm')
        ADVANCE(206);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(203);
      END_STATE();
    case 204:
      if (lookahead == '+')
        ADVANCE(50);
      if (lookahead == '-')
        ADVANCE(207);
      END_STATE();
    case 205:
      if (lookahead == '/')
        ADVANCE(54);
      END_STATE();
    case 206:
      if (lookahead == 'o')
        ADVANCE(92);
      END_STATE();
    case 207:
      if (lookahead == '-')
        ADVANCE(54);
      END_STATE();
    case 208:
      if (lookahead == '\'')
        ADVANCE(6);
      if (lookahead == '(')
        ADVANCE(7);
      if (lookahead == '-')
        ADVANCE(204);
      if (lookahead == '.')
        ADVANCE(209);
      if (lookahead == '/')
        ADVANCE(205);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(208);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 211:
      if (lookahead == '-')
        ADVANCE(204);
      if (lookahead == '/')
        ADVANCE(205);
      if (lookahead == 'd')
        ADVANCE(212);
      if (lookahead == 'e')
        ADVANCE(213);
      if (lookahead == 'f')
        ADVANCE(214);
      if (lookahead == 'i')
        ADVANCE(215);
      if (lookahead == 'm')
        ADVANCE(216);
      if (lookahead == 'p')
        ADVANCE(217);
      if (lookahead == 'r')
        ADVANCE(218);
      if (lookahead == 's')
        ADVANCE(219);
      if (lookahead == 'u')
        ADVANCE(220);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(211);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e')
        ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n')
        ADVANCE(222);
      if (lookahead == 'x')
        ADVANCE(223);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '3')
        ADVANCE(224);
      if (lookahead == '6')
        ADVANCE(225);
      if (lookahead == 'u')
        ADVANCE(226);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '1')
        ADVANCE(227);
      if (lookahead == '3')
        ADVANCE(228);
      if (lookahead == '6')
        ADVANCE(229);
      if (lookahead == '8')
        ADVANCE(230);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e')
        ADVANCE(231);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r')
        ADVANCE(232);
      if (lookahead == 'u')
        ADVANCE(233);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e')
        ADVANCE(234);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '1')
        ADVANCE(235);
      if (lookahead == '3')
        ADVANCE(236);
      if (lookahead == '8')
        ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '1')
        ADVANCE(238);
      if (lookahead == '3')
        ADVANCE(239);
      if (lookahead == '6')
        ADVANCE(240);
      if (lookahead == '8')
        ADVANCE(241);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c')
        ADVANCE(242);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd')
        ADVANCE(243);
      if (lookahead == 'u')
        ADVANCE(244);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't')
        ADVANCE(245);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '2')
        ADVANCE(246);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '4')
        ADVANCE(247);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n')
        ADVANCE(248);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '6')
        ADVANCE(249);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '2')
        ADVANCE(250);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '4')
        ADVANCE(251);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(anon_sym_i8);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't')
        ADVANCE(252);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i')
        ADVANCE(253);
      if (lookahead == 'o')
        ADVANCE(254);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'b')
        ADVANCE(255);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a')
        ADVANCE(256);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '6')
        ADVANCE(257);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '2')
        ADVANCE(258);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(anon_sym_s8);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '6')
        ADVANCE(259);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '2')
        ADVANCE(260);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '4')
        ADVANCE(261);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(anon_sym_u8);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l')
        ADVANCE(262);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(anon_sym_end);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'm')
        ADVANCE(263);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e')
        ADVANCE(264);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(anon_sym_f32);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(anon_sym_f64);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c')
        ADVANCE(265);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(anon_sym_i16);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(anon_sym_i32);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(anon_sym_i64);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'h')
        ADVANCE(266);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'v')
        ADVANCE(267);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't')
        ADVANCE(268);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l')
        ADVANCE(269);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd')
        ADVANCE(270);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(anon_sym_s16);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(anon_sym_s32);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(anon_sym_u16);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(anon_sym_u32);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(anon_sym_u64);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a')
        ADVANCE(271);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(anon_sym_enum);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r')
        ADVANCE(272);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't')
        ADVANCE(273);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o')
        ADVANCE(274);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a')
        ADVANCE(275);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e')
        ADVANCE(276);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i')
        ADVANCE(277);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o')
        ADVANCE(278);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r')
        ADVANCE(279);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n')
        ADVANCE(280);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i')
        ADVANCE(281);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd')
        ADVANCE(282);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't')
        ADVANCE(283);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c')
        ADVANCE(284);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's')
        ADVANCE(285);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n')
        ADVANCE(286);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e')
        ADVANCE(287);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a')
        ADVANCE(288);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o')
        ADVANCE(289);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(anon_sym_method);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e')
        ADVANCE(290);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't')
        ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'h')
        ADVANCE(292);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l')
        ADVANCE(293);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(sym_is_declare);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l')
        ADVANCE(294);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n')
        ADVANCE(295);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(anon_sym_private);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e')
        ADVANCE(296);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(anon_sym_publish);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'y')
        ADVANCE(297);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(sym_is_external);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(anon_sym_function);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd')
        ADVANCE(298);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(sym_readonly);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(anon_sym_protected);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 299:
      if (lookahead == '%')
        ADVANCE(300);
      if (lookahead == '&')
        ADVANCE(301);
      if (lookahead == '*')
        ADVANCE(9);
      if (lookahead == '+')
        ADVANCE(302);
      if (lookahead == ',')
        ADVANCE(11);
      if (lookahead == '-')
        ADVANCE(303);
      if (lookahead == '.')
        ADVANCE(209);
      if (lookahead == '/')
        ADVANCE(304);
      if (lookahead == ':')
        ADVANCE(305);
      if (lookahead == '<')
        ADVANCE(306);
      if (lookahead == '>')
        ADVANCE(307);
      if (lookahead == '[')
        ADVANCE(20);
      if (lookahead == '^')
        ADVANCE(308);
      if (lookahead == '|')
        ADVANCE(309);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(299);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 300:
      if (lookahead == '=')
        ADVANCE(44);
      END_STATE();
    case 301:
      if (lookahead == '=')
        ADVANCE(46);
      END_STATE();
    case 302:
      if (lookahead == '+')
        ADVANCE(48);
      if (lookahead == '=')
        ADVANCE(49);
      END_STATE();
    case 303:
      if (lookahead == '+')
        ADVANCE(50);
      if (lookahead == '-')
        ADVANCE(51);
      if (lookahead == '=')
        ADVANCE(52);
      END_STATE();
    case 304:
      if (lookahead == '/')
        ADVANCE(54);
      if (lookahead == '=')
        ADVANCE(55);
      END_STATE();
    case 305:
      if (lookahead == '=')
        ADVANCE(62);
      END_STATE();
    case 306:
      if (lookahead == '<')
        ADVANCE(310);
      END_STATE();
    case 307:
      if (lookahead == '>')
        ADVANCE(311);
      END_STATE();
    case 308:
      if (lookahead == '=')
        ADVANCE(77);
      END_STATE();
    case 309:
      if (lookahead == '=')
        ADVANCE(107);
      END_STATE();
    case 310:
      if (lookahead == '=')
        ADVANCE(112);
      END_STATE();
    case 311:
      if (lookahead == '=')
        ADVANCE(113);
      END_STATE();
    case 312:
      if (lookahead == '-')
        ADVANCE(204);
      if (lookahead == '/')
        ADVANCE(205);
      if (lookahead == 'f')
        ADVANCE(214);
      if (lookahead == 'i')
        ADVANCE(215);
      if (lookahead == 'm')
        ADVANCE(216);
      if (lookahead == 'r')
        ADVANCE(218);
      if (lookahead == 's')
        ADVANCE(219);
      if (lookahead == 'u')
        ADVANCE(220);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(312);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 313:
      if (lookahead == '-')
        ADVANCE(204);
      if (lookahead == '/')
        ADVANCE(205);
      if (lookahead == 'f')
        ADVANCE(214);
      if (lookahead == 'i')
        ADVANCE(215);
      if (lookahead == 'm')
        ADVANCE(216);
      if (lookahead == 'p')
        ADVANCE(217);
      if (lookahead == 'r')
        ADVANCE(218);
      if (lookahead == 's')
        ADVANCE(219);
      if (lookahead == 'u')
        ADVANCE(220);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(313);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 314:
      if (lookahead == ')')
        ADVANCE(8);
      if (lookahead == '-')
        ADVANCE(204);
      if (lookahead == '/')
        ADVANCE(205);
      if (lookahead == 'f')
        ADVANCE(315);
      if (lookahead == 'i')
        ADVANCE(215);
      if (lookahead == 's')
        ADVANCE(219);
      if (lookahead == 'u')
        ADVANCE(220);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(314);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '3')
        ADVANCE(224);
      if (lookahead == '6')
        ADVANCE(225);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 316:
      if (lookahead == '%')
        ADVANCE(300);
      if (lookahead == '&')
        ADVANCE(301);
      if (lookahead == '*')
        ADVANCE(9);
      if (lookahead == '+')
        ADVANCE(302);
      if (lookahead == '-')
        ADVANCE(303);
      if (lookahead == '/')
        ADVANCE(304);
      if (lookahead == ':')
        ADVANCE(305);
      if (lookahead == '<')
        ADVANCE(306);
      if (lookahead == '>')
        ADVANCE(307);
      if (lookahead == '[')
        ADVANCE(20);
      if (lookahead == '^')
        ADVANCE(308);
      if (lookahead == '|')
        ADVANCE(309);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(316);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 317:
      if (lookahead == '"')
        ADVANCE(3);
      if (lookahead == '\'')
        ADVANCE(6);
      if (lookahead == '(')
        ADVANCE(7);
      if (lookahead == '-')
        ADVANCE(204);
      if (lookahead == '.')
        ADVANCE(318);
      if (lookahead == '/')
        ADVANCE(205);
      if (lookahead == '0')
        ADVANCE(319);
      if (lookahead == 'e')
        ADVANCE(320);
      if (lookahead == 'f')
        ADVANCE(315);
      if (lookahead == 'g')
        ADVANCE(321);
      if (lookahead == 'i')
        ADVANCE(322);
      if (lookahead == 'n')
        ADVANCE(323);
      if (lookahead == 'p')
        ADVANCE(217);
      if (lookahead == 'r')
        ADVANCE(324);
      if (lookahead == 's')
        ADVANCE(325);
      if (lookahead == 'u')
        ADVANCE(220);
      if (lookahead == 'w')
        ADVANCE(326);
      if (lookahead == '{')
        ADVANCE(37);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(317);
      if (('1' <= lookahead && lookahead <= '9'))
        ADVANCE(60);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 318:
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(53);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.')
        ADVANCE(53);
      if (lookahead == 'b')
        ADVANCE(56);
      if (lookahead == 'f')
        ADVANCE(57);
      if (lookahead == 'l')
        ADVANCE(58);
      if (lookahead == 'x')
        ADVANCE(59);
      if (lookahead == '8' ||
          lookahead == '9')
        ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '7'))
        ADVANCE(61);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n')
        ADVANCE(327);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o')
        ADVANCE(328);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '1')
        ADVANCE(227);
      if (lookahead == '3')
        ADVANCE(228);
      if (lookahead == '6')
        ADVANCE(229);
      if (lookahead == '8')
        ADVANCE(230);
      if (lookahead == 'f')
        ADVANCE(329);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u')
        ADVANCE(330);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 324:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e')
        ADVANCE(331);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 325:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '1')
        ADVANCE(235);
      if (lookahead == '3')
        ADVANCE(236);
      if (lookahead == '8')
        ADVANCE(237);
      if (lookahead == 'e')
        ADVANCE(332);
      if (lookahead == 'w')
        ADVANCE(333);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'h')
        ADVANCE(334);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 327:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd')
        ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 328:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't')
        ADVANCE(335);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 329:
      ACCEPT_TOKEN(anon_sym_if);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 330:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l')
        ADVANCE(336);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 331:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a')
        ADVANCE(256);
      if (lookahead == 't')
        ADVANCE(337);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 332:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c')
        ADVANCE(338);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 333:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i')
        ADVANCE(339);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 334:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i')
        ADVANCE(340);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 335:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o')
        ADVANCE(341);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 336:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l')
        ADVANCE(342);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 337:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u')
        ADVANCE(343);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 338:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't')
        ADVANCE(344);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 339:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't')
        ADVANCE(345);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 340:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l')
        ADVANCE(346);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 341:
      ACCEPT_TOKEN(anon_sym_goto);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 342:
      ACCEPT_TOKEN(sym_null);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 343:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r')
        ADVANCE(347);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 344:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i')
        ADVANCE(348);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 345:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c')
        ADVANCE(349);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 346:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e')
        ADVANCE(350);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 347:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n')
        ADVANCE(351);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 348:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o')
        ADVANCE(352);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 349:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'h')
        ADVANCE(353);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 350:
      ACCEPT_TOKEN(anon_sym_while);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 351:
      ACCEPT_TOKEN(anon_sym_return);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 352:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n')
        ADVANCE(354);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 353:
      ACCEPT_TOKEN(anon_sym_switch);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 354:
      ACCEPT_TOKEN(anon_sym_section);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 355:
      if (lookahead == '-')
        ADVANCE(204);
      if (lookahead == '/')
        ADVANCE(205);
      if (lookahead == ']')
        ADVANCE(22);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(355);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(356);
      END_STATE();
    case 356:
      ACCEPT_TOKEN(sym_integer);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(356);
      END_STATE();
    case 357:
      if (lookahead == '(')
        ADVANCE(7);
      if (lookahead == '-')
        ADVANCE(204);
      if (lookahead == '.')
        ADVANCE(209);
      if (lookahead == '/')
        ADVANCE(205);
      if (lookahead == 'r')
        ADVANCE(358);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(357);
      END_STATE();
    case 358:
      if (lookahead == 'e')
        ADVANCE(359);
      END_STATE();
    case 359:
      if (lookahead == 't')
        ADVANCE(360);
      END_STATE();
    case 360:
      if (lookahead == 'u')
        ADVANCE(361);
      END_STATE();
    case 361:
      if (lookahead == 'r')
        ADVANCE(362);
      END_STATE();
    case 362:
      if (lookahead == 'n')
        ADVANCE(363);
      END_STATE();
    case 363:
      if (lookahead == 's')
        ADVANCE(364);
      END_STATE();
    case 364:
      ACCEPT_TOKEN(anon_sym_returns);
      END_STATE();
    case 365:
      if (lookahead == ')')
        ADVANCE(8);
      if (lookahead == ',')
        ADVANCE(11);
      if (lookahead == '-')
        ADVANCE(204);
      if (lookahead == '.')
        ADVANCE(209);
      if (lookahead == '/')
        ADVANCE(205);
      if (lookahead == ':')
        ADVANCE(305);
      if (lookahead == 'd')
        ADVANCE(212);
      if (lookahead == 'e')
        ADVANCE(213);
      if (lookahead == 'f')
        ADVANCE(214);
      if (lookahead == 'i')
        ADVANCE(215);
      if (lookahead == 'm')
        ADVANCE(216);
      if (lookahead == 'p')
        ADVANCE(217);
      if (lookahead == 'r')
        ADVANCE(218);
      if (lookahead == 's')
        ADVANCE(219);
      if (lookahead == 'u')
        ADVANCE(220);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(365);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 366:
      if (lookahead == '!')
        ADVANCE(367);
      if (lookahead == '"')
        ADVANCE(3);
      if (lookahead == '&')
        ADVANCE(368);
      if (lookahead == '\'')
        ADVANCE(6);
      if (lookahead == '(')
        ADVANCE(7);
      if (lookahead == '*')
        ADVANCE(369);
      if (lookahead == '-')
        ADVANCE(370);
      if (lookahead == '.')
        ADVANCE(318);
      if (lookahead == '/')
        ADVANCE(205);
      if (lookahead == '0')
        ADVANCE(319);
      if (lookahead == 'n')
        ADVANCE(323);
      if (lookahead == '{')
        ADVANCE(37);
      if (lookahead == '~')
        ADVANCE(40);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(366);
      if (('1' <= lookahead && lookahead <= '9'))
        ADVANCE(60);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 367:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 368:
      ACCEPT_TOKEN(anon_sym_AMP);
      END_STATE();
    case 369:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 370:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '+')
        ADVANCE(50);
      if (lookahead == '-')
        ADVANCE(207);
      END_STATE();
    case 371:
      if (lookahead == '"')
        ADVANCE(3);
      if (lookahead == '-')
        ADVANCE(372);
      if (lookahead == '/')
        ADVANCE(373);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        ADVANCE(374);
      if (lookahead != 0)
        ADVANCE(375);
      END_STATE();
    case 372:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '+')
        ADVANCE(376);
      if (lookahead == '-')
        ADVANCE(377);
      if (lookahead != 0 &&
          lookahead != '"')
        ADVANCE(375);
      END_STATE();
    case 373:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '/')
        ADVANCE(378);
      if (lookahead != 0 &&
          lookahead != '"')
        ADVANCE(375);
      END_STATE();
    case 374:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '-')
        ADVANCE(372);
      if (lookahead == '/')
        ADVANCE(373);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        ADVANCE(374);
      if (lookahead != 0 &&
          lookahead != '"')
        ADVANCE(375);
      END_STATE();
    case 375:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead != 0 &&
          lookahead != '"')
        ADVANCE(375);
      END_STATE();
    case 376:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '"')
        ADVANCE(50);
      if (lookahead == '+')
        ADVANCE(379);
      if (lookahead != 0)
        ADVANCE(376);
      END_STATE();
    case 377:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '-')
        ADVANCE(378);
      if (lookahead != 0 &&
          lookahead != '"')
        ADVANCE(375);
      END_STATE();
    case 378:
      ACCEPT_TOKEN(sym__comment);
      if (lookahead == '\n')
        ADVANCE(375);
      if (lookahead == '"')
        ADVANCE(54);
      if (lookahead != 0)
        ADVANCE(378);
      END_STATE();
    case 379:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '"')
        ADVANCE(50);
      if (lookahead == '+')
        ADVANCE(379);
      if (lookahead == '-')
        ADVANCE(380);
      if (lookahead != 0)
        ADVANCE(376);
      END_STATE();
    case 380:
      ACCEPT_TOKEN(sym__comment);
      if (lookahead != 0 &&
          lookahead != '"')
        ADVANCE(375);
      END_STATE();
    case 381:
      if (lookahead == '-')
        ADVANCE(204);
      if (lookahead == '/')
        ADVANCE(205);
      if (lookahead == 'f')
        ADVANCE(315);
      if (lookahead == 'i')
        ADVANCE(215);
      if (lookahead == 'r')
        ADVANCE(218);
      if (lookahead == 's')
        ADVANCE(219);
      if (lookahead == 'u')
        ADVANCE(220);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(381);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 382:
      if (lookahead == '-')
        ADVANCE(383);
      if (lookahead == '/')
        ADVANCE(384);
      if (lookahead == '\\')
        ADVANCE(21);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(382);
      if (lookahead != 0 &&
          lookahead != '\'')
        ADVANCE(42);
      END_STATE();
    case 383:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == '+')
        ADVANCE(50);
      if (lookahead == '-')
        ADVANCE(207);
      END_STATE();
    case 384:
      ACCEPT_TOKEN(aux_sym_character_token1);
      if (lookahead == '/')
        ADVANCE(54);
      END_STATE();
    case 385:
      if (lookahead == '-')
        ADVANCE(204);
      if (lookahead == '/')
        ADVANCE(205);
      if (lookahead == 'e')
        ADVANCE(386);
      if (lookahead == 'f')
        ADVANCE(387);
      if (lookahead == 'm')
        ADVANCE(388);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(385);
      END_STATE();
    case 386:
      if (lookahead == 'n')
        ADVANCE(389);
      END_STATE();
    case 387:
      if (lookahead == 'u')
        ADVANCE(84);
      END_STATE();
    case 388:
      if (lookahead == 'e')
        ADVANCE(91);
      END_STATE();
    case 389:
      if (lookahead == 'd')
        ADVANCE(117);
      END_STATE();
    case 390:
      if (lookahead == '%')
        ADVANCE(300);
      if (lookahead == '&')
        ADVANCE(301);
      if (lookahead == '*')
        ADVANCE(391);
      if (lookahead == '+')
        ADVANCE(302);
      if (lookahead == ',')
        ADVANCE(11);
      if (lookahead == '-')
        ADVANCE(303);
      if (lookahead == '.')
        ADVANCE(209);
      if (lookahead == '/')
        ADVANCE(304);
      if (lookahead == ':')
        ADVANCE(305);
      if (lookahead == '<')
        ADVANCE(306);
      if (lookahead == '>')
        ADVANCE(307);
      if (lookahead == '^')
        ADVANCE(308);
      if (lookahead == '|')
        ADVANCE(309);
      if (lookahead == '}')
        ADVANCE(39);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(390);
      END_STATE();
    case 391:
      if (lookahead == '=')
        ADVANCE(47);
      END_STATE();
    case 392:
      if (lookahead == ')')
        ADVANCE(8);
      if (lookahead == ',')
        ADVANCE(11);
      if (lookahead == '-')
        ADVANCE(204);
      if (lookahead == '/')
        ADVANCE(205);
      if (lookahead == ':')
        ADVANCE(305);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(392);
      END_STATE();
    case 393:
      if (lookahead == ')')
        ADVANCE(8);
      if (lookahead == '-')
        ADVANCE(204);
      if (lookahead == '/')
        ADVANCE(205);
      if (lookahead == 'f')
        ADVANCE(315);
      if (lookahead == 'i')
        ADVANCE(215);
      if (lookahead == 'p')
        ADVANCE(217);
      if (lookahead == 'r')
        ADVANCE(218);
      if (lookahead == 's')
        ADVANCE(219);
      if (lookahead == 'u')
        ADVANCE(220);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(393);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 394:
      if (lookahead == '!')
        ADVANCE(395);
      if (lookahead == '%')
        ADVANCE(4);
      if (lookahead == '&')
        ADVANCE(5);
      if (lookahead == ')')
        ADVANCE(8);
      if (lookahead == '*')
        ADVANCE(9);
      if (lookahead == '+')
        ADVANCE(10);
      if (lookahead == ',')
        ADVANCE(11);
      if (lookahead == '-')
        ADVANCE(12);
      if (lookahead == '.')
        ADVANCE(209);
      if (lookahead == '/')
        ADVANCE(14);
      if (lookahead == ':')
        ADVANCE(305);
      if (lookahead == '<')
        ADVANCE(17);
      if (lookahead == '=')
        ADVANCE(396);
      if (lookahead == '>')
        ADVANCE(19);
      if (lookahead == '^')
        ADVANCE(23);
      if (lookahead == 'd')
        ADVANCE(212);
      if (lookahead == 'e')
        ADVANCE(213);
      if (lookahead == 'f')
        ADVANCE(214);
      if (lookahead == 'i')
        ADVANCE(215);
      if (lookahead == 'm')
        ADVANCE(216);
      if (lookahead == 'p')
        ADVANCE(217);
      if (lookahead == 'r')
        ADVANCE(218);
      if (lookahead == 's')
        ADVANCE(219);
      if (lookahead == 'u')
        ADVANCE(220);
      if (lookahead == '|')
        ADVANCE(38);
      if (lookahead == '}')
        ADVANCE(39);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(394);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 395:
      if (lookahead == '=')
        ADVANCE(43);
      END_STATE();
    case 396:
      if (lookahead == '=')
        ADVANCE(65);
      END_STATE();
    case 397:
      if (lookahead == ',')
        ADVANCE(11);
      if (lookahead == '-')
        ADVANCE(204);
      if (lookahead == '/')
        ADVANCE(205);
      if (lookahead == '}')
        ADVANCE(39);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(397);
      END_STATE();
    case 398:
      if (lookahead == '!')
        ADVANCE(395);
      if (lookahead == '%')
        ADVANCE(4);
      if (lookahead == '&')
        ADVANCE(5);
      if (lookahead == ')')
        ADVANCE(8);
      if (lookahead == '*')
        ADVANCE(9);
      if (lookahead == '+')
        ADVANCE(10);
      if (lookahead == '-')
        ADVANCE(12);
      if (lookahead == '/')
        ADVANCE(14);
      if (lookahead == ':')
        ADVANCE(305);
      if (lookahead == '<')
        ADVANCE(17);
      if (lookahead == '=')
        ADVANCE(396);
      if (lookahead == '>')
        ADVANCE(19);
      if (lookahead == '^')
        ADVANCE(23);
      if (lookahead == '|')
        ADVANCE(38);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(398);
      END_STATE();
    case 399:
      if (lookahead == '"')
        ADVANCE(3);
      if (lookahead == '\'')
        ADVANCE(6);
      if (lookahead == '(')
        ADVANCE(7);
      if (lookahead == '-')
        ADVANCE(204);
      if (lookahead == '.')
        ADVANCE(13);
      if (lookahead == '/')
        ADVANCE(205);
      if (lookahead == '0')
        ADVANCE(319);
      if (lookahead == 'f')
        ADVANCE(315);
      if (lookahead == 'g')
        ADVANCE(321);
      if (lookahead == 'i')
        ADVANCE(322);
      if (lookahead == 'n')
        ADVANCE(323);
      if (lookahead == 'p')
        ADVANCE(217);
      if (lookahead == 'r')
        ADVANCE(324);
      if (lookahead == 's')
        ADVANCE(325);
      if (lookahead == 'u')
        ADVANCE(220);
      if (lookahead == 'w')
        ADVANCE(326);
      if (lookahead == '{')
        ADVANCE(37);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(399);
      if (('1' <= lookahead && lookahead <= '9'))
        ADVANCE(60);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 400:
      if (lookahead == ')')
        ADVANCE(8);
      if (lookahead == ',')
        ADVANCE(11);
      if (lookahead == '-')
        ADVANCE(204);
      if (lookahead == '.')
        ADVANCE(209);
      if (lookahead == '/')
        ADVANCE(205);
      if (lookahead == '}')
        ADVANCE(39);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(400);
      END_STATE();
    case 401:
      if (lookahead == '*')
        ADVANCE(369);
      if (lookahead == ',')
        ADVANCE(11);
      if (lookahead == '-')
        ADVANCE(204);
      if (lookahead == '.')
        ADVANCE(209);
      if (lookahead == '/')
        ADVANCE(205);
      if (lookahead == '[')
        ADVANCE(20);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(401);
      END_STATE();
    case 402:
      if (lookahead == '%')
        ADVANCE(300);
      if (lookahead == '&')
        ADVANCE(301);
      if (lookahead == ')')
        ADVANCE(8);
      if (lookahead == '*')
        ADVANCE(391);
      if (lookahead == '+')
        ADVANCE(403);
      if (lookahead == ',')
        ADVANCE(11);
      if (lookahead == '-')
        ADVANCE(404);
      if (lookahead == '.')
        ADVANCE(209);
      if (lookahead == '/')
        ADVANCE(304);
      if (lookahead == ':')
        ADVANCE(305);
      if (lookahead == '<')
        ADVANCE(306);
      if (lookahead == '>')
        ADVANCE(307);
      if (lookahead == '^')
        ADVANCE(308);
      if (lookahead == 'd')
        ADVANCE(212);
      if (lookahead == 'e')
        ADVANCE(213);
      if (lookahead == 'f')
        ADVANCE(214);
      if (lookahead == 'i')
        ADVANCE(215);
      if (lookahead == 'm')
        ADVANCE(216);
      if (lookahead == 'p')
        ADVANCE(217);
      if (lookahead == 'r')
        ADVANCE(218);
      if (lookahead == 's')
        ADVANCE(219);
      if (lookahead == 'u')
        ADVANCE(220);
      if (lookahead == '|')
        ADVANCE(309);
      if (lookahead == '}')
        ADVANCE(39);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(402);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z'))
        ADVANCE(210);
      END_STATE();
    case 403:
      if (lookahead == '=')
        ADVANCE(49);
      END_STATE();
    case 404:
      if (lookahead == '+')
        ADVANCE(50);
      if (lookahead == '-')
        ADVANCE(207);
      if (lookahead == '=')
        ADVANCE(52);
      END_STATE();
    case 405:
      if (lookahead == '-')
        ADVANCE(204);
      if (lookahead == '/')
        ADVANCE(205);
      if (lookahead == 'c')
        ADVANCE(406);
      if (lookahead == 'd')
        ADVANCE(407);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(405);
      END_STATE();
    case 406:
      if (lookahead == 'a')
        ADVANCE(78);
      END_STATE();
    case 407:
      if (lookahead == 'e')
        ADVANCE(408);
      END_STATE();
    case 408:
      if (lookahead == 'f')
        ADVANCE(116);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 203},
  [2] = {.lex_state = 208},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 203},
  [5] = {.lex_state = 208},
  [6] = {.lex_state = 203},
  [7] = {.lex_state = 211},
  [8] = {.lex_state = 299},
  [9] = {.lex_state = 208},
  [10] = {.lex_state = 312},
  [11] = {.lex_state = 313},
  [12] = {.lex_state = 208},
  [13] = {.lex_state = 314},
  [14] = {.lex_state = 208},
  [15] = {.lex_state = 203},
  [16] = {.lex_state = 316},
  [17] = {.lex_state = 211},
  [18] = {.lex_state = 208},
  [19] = {.lex_state = 208},
  [20] = {.lex_state = 208},
  [21] = {.lex_state = 312},
  [22] = {.lex_state = 317},
  [23] = {.lex_state = 211},
  [24] = {.lex_state = 208},
  [25] = {.lex_state = 312},
  [26] = {.lex_state = 208},
  [27] = {.lex_state = 208},
  [28] = {.lex_state = 208},
  [29] = {.lex_state = 299},
  [30] = {.lex_state = 355},
  [31] = {.lex_state = 316},
  [32] = {.lex_state = 316},
  [33] = {.lex_state = 211},
  [34] = {.lex_state = 208},
  [35] = {.lex_state = 203},
  [36] = {.lex_state = 357},
  [37] = {.lex_state = 365},
  [38] = {.lex_state = 314},
  [39] = {.lex_state = 208},
  [40] = {.lex_state = 366},
  [41] = {.lex_state = 208},
  [42] = {.lex_state = 371},
  [43] = {.lex_state = 381},
  [44] = {.lex_state = 208},
  [45] = {.lex_state = 366},
  [46] = {.lex_state = 366},
  [47] = {.lex_state = 208},
  [48] = {.lex_state = 208},
  [49] = {.lex_state = 382},
  [50] = {.lex_state = 316},
  [51] = {.lex_state = 208},
  [52] = {.lex_state = 385},
  [53] = {.lex_state = 317},
  [54] = {.lex_state = 208},
  [55] = {.lex_state = 390},
  [56] = {.lex_state = 208},
  [57] = {.lex_state = 299},
  [58] = {.lex_state = 381},
  [59] = {.lex_state = 208},
  [60] = {.lex_state = 299},
  [61] = {.lex_state = 357},
  [62] = {.lex_state = 208},
  [63] = {.lex_state = 365},
  [64] = {.lex_state = 392},
  [65] = {.lex_state = 392},
  [66] = {.lex_state = 355},
  [67] = {.lex_state = 299},
  [68] = {.lex_state = 316},
  [69] = {.lex_state = 316},
  [70] = {.lex_state = 316},
  [71] = {.lex_state = 203},
  [72] = {.lex_state = 317},
  [73] = {.lex_state = 393},
  [74] = {.lex_state = 314},
  [75] = {.lex_state = 357},
  [76] = {.lex_state = 208},
  [77] = {.lex_state = 366},
  [78] = {.lex_state = 365},
  [79] = {.lex_state = 208},
  [80] = {.lex_state = 357},
  [81] = {.lex_state = 208},
  [82] = {.lex_state = 390},
  [83] = {.lex_state = 208},
  [84] = {.lex_state = 394},
  [85] = {.lex_state = 371},
  [86] = {.lex_state = 208},
  [87] = {.lex_state = 397},
  [88] = {.lex_state = 397},
  [89] = {.lex_state = 366},
  [90] = {.lex_state = 398},
  [91] = {.lex_state = 314},
  [92] = {.lex_state = 366},
  [93] = {.lex_state = 208},
  [94] = {.lex_state = 366},
  [95] = {.lex_state = 399},
  [96] = {.lex_state = 208},
  [97] = {.lex_state = 208},
  [98] = {.lex_state = 208},
  [99] = {.lex_state = 208},
  [100] = {.lex_state = 317},
  [101] = {.lex_state = 208},
  [102] = {.lex_state = 317},
  [103] = {.lex_state = 400},
  [104] = {.lex_state = 400},
  [105] = {.lex_state = 211},
  [106] = {.lex_state = 366},
  [107] = {.lex_state = 366},
  [108] = {.lex_state = 211},
  [109] = {.lex_state = 357},
  [110] = {.lex_state = 208},
  [111] = {.lex_state = 357},
  [112] = {.lex_state = 365},
  [113] = {.lex_state = 392},
  [114] = {.lex_state = 208},
  [115] = {.lex_state = 208},
  [116] = {.lex_state = 392},
  [117] = {.lex_state = 299},
  [118] = {.lex_state = 357},
  [119] = {.lex_state = 392},
  [120] = {.lex_state = 314},
  [121] = {.lex_state = 208},
  [122] = {.lex_state = 401},
  [123] = {.lex_state = 401},
  [124] = {.lex_state = 317},
  [125] = {.lex_state = 208},
  [126] = {.lex_state = 365},
  [127] = {.lex_state = 365},
  [128] = {.lex_state = 357},
  [129] = {.lex_state = 317},
  [130] = {.lex_state = 394},
  [131] = {.lex_state = 371},
  [132] = {.lex_state = 402},
  [133] = {.lex_state = 366},
  [134] = {.lex_state = 397},
  [135] = {.lex_state = 366},
  [136] = {.lex_state = 394},
  [137] = {.lex_state = 366},
  [138] = {.lex_state = 314},
  [139] = {.lex_state = 398},
  [140] = {.lex_state = 314},
  [141] = {.lex_state = 366},
  [142] = {.lex_state = 317},
  [143] = {.lex_state = 317},
  [144] = {.lex_state = 394},
  [145] = {.lex_state = 405},
  [146] = {.lex_state = 211},
  [147] = {.lex_state = 400},
  [148] = {.lex_state = 211},
  [149] = {.lex_state = 208},
  [150] = {.lex_state = 357},
  [151] = {.lex_state = 392},
  [152] = {.lex_state = 208},
  [153] = {.lex_state = 208},
  [154] = {.lex_state = 392},
  [155] = {.lex_state = 393},
  [156] = {.lex_state = 392},
  [157] = {.lex_state = 357},
  [158] = {.lex_state = 314},
  [159] = {.lex_state = 401},
  [160] = {.lex_state = 401},
  [161] = {.lex_state = 401},
  [162] = {.lex_state = 317},
  [163] = {.lex_state = 365},
  [164] = {.lex_state = 208},
  [165] = {.lex_state = 317},
  [166] = {.lex_state = 317},
  [167] = {.lex_state = 208},
  [168] = {.lex_state = 397},
  [169] = {.lex_state = 397},
  [170] = {.lex_state = 314},
  [171] = {.lex_state = 394},
  [172] = {.lex_state = 399},
  [173] = {.lex_state = 366},
  [174] = {.lex_state = 314},
  [175] = {.lex_state = 317},
  [176] = {.lex_state = 317},
  [177] = {.lex_state = 208},
  [178] = {.lex_state = 208},
  [179] = {.lex_state = 208},
  [180] = {.lex_state = 385},
  [181] = {.lex_state = 405},
  [182] = {.lex_state = 211},
  [183] = {.lex_state = 208},
  [184] = {.lex_state = 211},
  [185] = {.lex_state = 208},
  [186] = {.lex_state = 392},
  [187] = {.lex_state = 392},
  [188] = {.lex_state = 401},
  [189] = {.lex_state = 401},
  [190] = {.lex_state = 401},
  [191] = {.lex_state = 401},
  [192] = {.lex_state = 401},
  [193] = {.lex_state = 317},
  [194] = {.lex_state = 208},
  [195] = {.lex_state = 208},
  [196] = {.lex_state = 394},
  [197] = {.lex_state = 314},
  [198] = {.lex_state = 399},
  [199] = {.lex_state = 208},
  [200] = {.lex_state = 208},
  [201] = {.lex_state = 208},
  [202] = {.lex_state = 317},
  [203] = {.lex_state = 317},
  [204] = {.lex_state = 208},
  [205] = {.lex_state = 385},
  [206] = {.lex_state = 405},
  [207] = {.lex_state = 211},
  [208] = {.lex_state = 211},
  [209] = {.lex_state = 399},
  [210] = {.lex_state = 317},
  [211] = {.lex_state = 405},
  [212] = {.lex_state = 317},
  [213] = {.lex_state = 208},
  [214] = {.lex_state = 208},
  [215] = {.lex_state = 208},
  [216] = {.lex_state = 405},
  [217] = {.lex_state = 317},
  [218] = {.lex_state = 208},
  [219] = {.lex_state = 208},
  [220] = {.lex_state = 208},
  [221] = {.lex_state = 385},
  [222] = {.lex_state = 208},
  [223] = {.lex_state = 208},
  [224] = {.lex_state = 405},
  [225] = {.lex_state = 385},
  [226] = {.lex_state = 405},
};

static uint16_t ts_parse_table[STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [anon_sym_BSLASHb] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_s32] = ACTIONS(1),
    [anon_sym_PIPE_PIPE] = ACTIONS(1),
    [anon_sym_LT_LT] = ACTIONS(1),
    [anon_sym_LT_EQ] = ACTIONS(1),
    [sym_null] = ACTIONS(1),
    [anon_sym_function] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [sym_readonly] = ACTIONS(1),
    [anon_sym_PLUS_PLUS] = ACTIONS(1),
    [anon_sym_protected] = ACTIONS(1),
    [anon_sym_BSLASHv] = ACTIONS(1),
    [anon_sym_s8] = ACTIONS(1),
    [anon_sym_BSLASHa] = ACTIONS(1),
    [anon_sym_enum] = ACTIONS(1),
    [anon_sym_BSLASHf] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_GT_GT] = ACTIONS(1),
    [anon_sym_PLUS_EQ] = ACTIONS(1),
    [anon_sym_BANG_EQ] = ACTIONS(1),
    [anon_sym_method] = ACTIONS(1),
    [anon_sym_private] = ACTIONS(1),
    [anon_sym_SLASH_EQ] = ACTIONS(1),
    [anon_sym_publish] = ACTIONS(1),
    [sym_oct] = ACTIONS(1),
    [anon_sym_s16] = ACTIONS(1),
    [sym_long] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_BSLASHn] = ACTIONS(1),
    [anon_sym_COLON_EQ] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [sym_is_declare] = ACTIONS(1),
    [anon_sym_DASH_EQ] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [anon_sym_if] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_switch] = ACTIONS(1),
    [anon_sym_PERCENT_EQ] = ACTIONS(1),
    [anon_sym_end] = ACTIONS(1),
    [sym_integer] = ACTIONS(1),
    [anon_sym_u8] = ACTIONS(1),
    [sym_float] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_BSLASHr] = ACTIONS(1),
    [anon_sym_i8] = ACTIONS(1),
    [anon_sym_return] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [sym_binary] = ACTIONS(1),
    [sym_is_external] = ACTIONS(1),
    [anon_sym_STAR_EQ] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [anon_sym_while] = ACTIONS(1),
    [anon_sym_DASH_DASH] = ACTIONS(1),
    [anon_sym_case] = ACTIONS(1),
    [anon_sym_AMP_EQ] = ACTIONS(1),
    [anon_sym_module] = ACTIONS(1),
    [anon_sym_CARET_EQ] = ACTIONS(1),
    [anon_sym_u16] = ACTIONS(1),
    [sym_double] = ACTIONS(1),
    [aux_sym_character_token1] = ACTIONS(1),
    [anon_sym_i16] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_BANG] = ACTIONS(1),
    [anon_sym_goto] = ACTIONS(1),
    [anon_sym_EQ_EQ] = ACTIONS(1),
    [anon_sym_CARET] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_default] = ACTIONS(1),
    [anon_sym_PIPE_EQ] = ACTIONS(1),
    [sym__comment] = ACTIONS(3),
    [anon_sym_GT_GT_EQ] = ACTIONS(1),
    [anon_sym_u32] = ACTIONS(1),
    [sym_hex] = ACTIONS(1),
    [anon_sym_f32] = ACTIONS(1),
    [anon_sym_BSLASH_BSLASH] = ACTIONS(1),
    [anon_sym_i32] = ACTIONS(1),
    [anon_sym_AMP] = ACTIONS(1),
    [anon_sym_TILDE] = ACTIONS(1),
    [anon_sym_section] = ACTIONS(1),
    [anon_sym_AMP_AMP] = ACTIONS(1),
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_GT_EQ] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_LT_LT_EQ] = ACTIONS(1),
    [anon_sym_u64] = ACTIONS(1),
    [anon_sym_BSLASHt] = ACTIONS(1),
    [anon_sym_f64] = ACTIONS(1),
    [anon_sym_BSLASH0] = ACTIONS(1),
    [anon_sym_i64] = ACTIONS(1),
  },
  [1] = {
    [sym_module_definition] = STATE(4),
    [sym_source_file] = STATE(3),
    [aux_sym_source_file_repeat1] = STATE(4),
    [sym__comment] = ACTIONS(3),
    [ts_builtin_sym_end] = ACTIONS(5),
    [anon_sym_module] = ACTIONS(7),
  },
  [2] = {
    [sym_identifier] = ACTIONS(9),
    [sym__comment] = ACTIONS(3),
  },
  [3] = {
    [sym__comment] = ACTIONS(3),
    [ts_builtin_sym_end] = ACTIONS(11),
  },
  [4] = {
    [aux_sym_source_file_repeat1] = STATE(6),
    [sym_module_definition] = STATE(6),
    [sym__comment] = ACTIONS(3),
    [ts_builtin_sym_end] = ACTIONS(13),
    [anon_sym_module] = ACTIONS(7),
  },
  [5] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(15),
  },
  [6] = {
    [aux_sym_source_file_repeat1] = STATE(6),
    [sym_module_definition] = STATE(6),
    [sym__comment] = ACTIONS(3),
    [ts_builtin_sym_end] = ACTIONS(17),
    [anon_sym_module] = ACTIONS(19),
  },
  [7] = {
    [sym_primitive_type] = STATE(16),
    [sym_access_control] = STATE(21),
    [sym_enum_definition] = STATE(17),
    [sym_variable_definition] = STATE(17),
    [sym_function_definition] = STATE(17),
    [sym_function_signature] = STATE(22),
    [sym_is_function] = STATE(19),
    [sym_is_method] = STATE(19),
    [sym_type] = STATE(20),
    [sym_declaration_definition] = STATE(17),
    [sym__definitions] = STATE(17),
    [aux_sym_module_definition_repeat1] = STATE(17),
    [sym_end_module] = STATE(18),
    [sym__base_type] = STATE(16),
    [anon_sym_i8] = ACTIONS(22),
    [anon_sym_method] = ACTIONS(24),
    [anon_sym_private] = ACTIONS(26),
    [anon_sym_s32] = ACTIONS(22),
    [anon_sym_publish] = ACTIONS(26),
    [anon_sym_u32] = ACTIONS(22),
    [anon_sym_s16] = ACTIONS(22),
    [anon_sym_f32] = ACTIONS(22),
    [sym_is_external] = ACTIONS(28),
    [anon_sym_i32] = ACTIONS(22),
    [sym__comment] = ACTIONS(3),
    [anon_sym_function] = ACTIONS(30),
    [sym_readonly] = ACTIONS(32),
    [anon_sym_protected] = ACTIONS(26),
    [anon_sym_u16] = ACTIONS(22),
    [anon_sym_s8] = ACTIONS(22),
    [sym_is_declare] = ACTIONS(28),
    [anon_sym_enum] = ACTIONS(34),
    [anon_sym_i16] = ACTIONS(22),
    [sym_identifier] = ACTIONS(36),
    [anon_sym_end] = ACTIONS(38),
    [anon_sym_u64] = ACTIONS(22),
    [anon_sym_u8] = ACTIONS(22),
    [anon_sym_f64] = ACTIONS(22),
    [anon_sym_i64] = ACTIONS(22),
  },
  [8] = {
    [sym_identifier] = ACTIONS(40),
    [anon_sym_STAR] = ACTIONS(40),
    [anon_sym_COMMA] = ACTIONS(40),
    [sym__comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(40),
    [anon_sym_DOT] = ACTIONS(40),
  },
  [9] = {
    [sym_identifier] = ACTIONS(42),
    [sym__comment] = ACTIONS(3),
  },
  [10] = {
    [anon_sym_i8] = ACTIONS(44),
    [anon_sym_method] = ACTIONS(44),
    [anon_sym_s32] = ACTIONS(44),
    [sym__comment] = ACTIONS(3),
    [anon_sym_u32] = ACTIONS(44),
    [anon_sym_s16] = ACTIONS(44),
    [anon_sym_f32] = ACTIONS(44),
    [anon_sym_i32] = ACTIONS(44),
    [anon_sym_function] = ACTIONS(44),
    [sym_readonly] = ACTIONS(44),
    [anon_sym_u16] = ACTIONS(44),
    [anon_sym_s8] = ACTIONS(44),
    [anon_sym_i16] = ACTIONS(44),
    [sym_identifier] = ACTIONS(44),
    [anon_sym_u64] = ACTIONS(44),
    [anon_sym_u8] = ACTIONS(44),
    [anon_sym_f64] = ACTIONS(44),
    [anon_sym_i64] = ACTIONS(44),
  },
  [11] = {
    [sym_primitive_type] = STATE(16),
    [sym_variable_definition] = STATE(23),
    [sym_is_function] = STATE(24),
    [sym_is_method] = STATE(24),
    [sym_type] = STATE(20),
    [sym_access_control] = STATE(25),
    [sym_function_signature] = STATE(23),
    [sym__base_type] = STATE(16),
    [anon_sym_i8] = ACTIONS(22),
    [anon_sym_method] = ACTIONS(24),
    [anon_sym_private] = ACTIONS(26),
    [anon_sym_s32] = ACTIONS(22),
    [anon_sym_publish] = ACTIONS(26),
    [anon_sym_u32] = ACTIONS(22),
    [anon_sym_s16] = ACTIONS(22),
    [anon_sym_f32] = ACTIONS(22),
    [sym__comment] = ACTIONS(3),
    [anon_sym_i32] = ACTIONS(22),
    [anon_sym_function] = ACTIONS(30),
    [sym_readonly] = ACTIONS(32),
    [anon_sym_protected] = ACTIONS(26),
    [anon_sym_u16] = ACTIONS(22),
    [anon_sym_s8] = ACTIONS(22),
    [anon_sym_i16] = ACTIONS(22),
    [sym_identifier] = ACTIONS(36),
    [anon_sym_u64] = ACTIONS(22),
    [anon_sym_u8] = ACTIONS(22),
    [anon_sym_f64] = ACTIONS(22),
    [anon_sym_i64] = ACTIONS(22),
  },
  [12] = {
    [sym_identifier] = ACTIONS(46),
    [sym__comment] = ACTIONS(3),
  },
  [13] = {
    [sym_primitive_type] = STATE(16),
    [sym_type] = STATE(26),
    [sym__base_type] = STATE(16),
    [anon_sym_i8] = ACTIONS(22),
    [anon_sym_s32] = ACTIONS(22),
    [sym__comment] = ACTIONS(3),
    [anon_sym_u32] = ACTIONS(22),
    [anon_sym_s16] = ACTIONS(22),
    [anon_sym_f32] = ACTIONS(22),
    [anon_sym_i32] = ACTIONS(22),
    [anon_sym_u16] = ACTIONS(22),
    [anon_sym_s8] = ACTIONS(22),
    [anon_sym_i16] = ACTIONS(22),
    [sym_identifier] = ACTIONS(36),
    [anon_sym_u64] = ACTIONS(22),
    [anon_sym_u8] = ACTIONS(22),
    [anon_sym_f64] = ACTIONS(22),
    [anon_sym_i64] = ACTIONS(22),
  },
  [14] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(48),
  },
  [15] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_module] = ACTIONS(50),
  },
  [16] = {
    [aux_sym_type_repeat2] = STATE(31),
    [aux_sym_type_repeat1] = STATE(32),
    [sym_pointer] = STATE(32),
    [sym_array] = STATE(31),
    [sym_identifier] = ACTIONS(52),
    [anon_sym_STAR] = ACTIONS(54),
    [sym__comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(56),
  },
  [17] = {
    [sym_primitive_type] = STATE(16),
    [sym_access_control] = STATE(21),
    [sym_enum_definition] = STATE(33),
    [sym_variable_definition] = STATE(33),
    [sym_function_definition] = STATE(33),
    [sym_function_signature] = STATE(22),
    [sym_is_function] = STATE(19),
    [sym_is_method] = STATE(19),
    [sym_type] = STATE(20),
    [sym_declaration_definition] = STATE(33),
    [sym__definitions] = STATE(33),
    [aux_sym_module_definition_repeat1] = STATE(33),
    [sym_end_module] = STATE(34),
    [sym__base_type] = STATE(16),
    [anon_sym_i8] = ACTIONS(22),
    [anon_sym_method] = ACTIONS(24),
    [anon_sym_private] = ACTIONS(26),
    [anon_sym_s32] = ACTIONS(22),
    [anon_sym_publish] = ACTIONS(26),
    [anon_sym_u32] = ACTIONS(22),
    [anon_sym_s16] = ACTIONS(22),
    [anon_sym_f32] = ACTIONS(22),
    [sym_is_external] = ACTIONS(28),
    [anon_sym_i32] = ACTIONS(22),
    [sym__comment] = ACTIONS(3),
    [anon_sym_function] = ACTIONS(30),
    [sym_readonly] = ACTIONS(32),
    [anon_sym_protected] = ACTIONS(26),
    [anon_sym_u16] = ACTIONS(22),
    [anon_sym_s8] = ACTIONS(22),
    [sym_is_declare] = ACTIONS(28),
    [anon_sym_enum] = ACTIONS(34),
    [anon_sym_i16] = ACTIONS(22),
    [sym_identifier] = ACTIONS(36),
    [anon_sym_end] = ACTIONS(38),
    [anon_sym_u64] = ACTIONS(22),
    [anon_sym_u8] = ACTIONS(22),
    [anon_sym_f64] = ACTIONS(22),
    [anon_sym_i64] = ACTIONS(22),
  },
  [18] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(58),
  },
  [19] = {
    [sym_identifier] = ACTIONS(60),
    [sym__comment] = ACTIONS(3),
  },
  [20] = {
    [sym_identifier] = ACTIONS(62),
    [sym__comment] = ACTIONS(3),
  },
  [21] = {
    [sym_primitive_type] = STATE(16),
    [sym_is_method] = STATE(39),
    [sym_type] = STATE(26),
    [sym_is_function] = STATE(39),
    [sym__base_type] = STATE(16),
    [anon_sym_i8] = ACTIONS(22),
    [anon_sym_method] = ACTIONS(24),
    [anon_sym_s32] = ACTIONS(22),
    [sym__comment] = ACTIONS(3),
    [anon_sym_u32] = ACTIONS(22),
    [anon_sym_s16] = ACTIONS(22),
    [anon_sym_f32] = ACTIONS(22),
    [anon_sym_i32] = ACTIONS(22),
    [anon_sym_function] = ACTIONS(30),
    [sym_readonly] = ACTIONS(64),
    [anon_sym_u16] = ACTIONS(22),
    [anon_sym_s8] = ACTIONS(22),
    [anon_sym_i16] = ACTIONS(22),
    [sym_identifier] = ACTIONS(36),
    [anon_sym_u64] = ACTIONS(22),
    [anon_sym_u8] = ACTIONS(22),
    [anon_sym_f64] = ACTIONS(22),
    [anon_sym_i64] = ACTIONS(22),
  },
  [22] = {
    [aux_sym_function_definition_repeat1] = STATE(53),
    [sym_end_method] = STATE(56),
    [sym_end_function] = STATE(56),
    [sym_type] = STATE(20),
    [sym__statement] = STATE(53),
    [sym_if_statement] = STATE(54),
    [sym_while_statement] = STATE(54),
    [sym_expression_statement] = STATE(54),
    [sym_collection] = STATE(60),
    [sym__value] = STATE(55),
    [sym__number] = STATE(55),
    [sym__end_function] = STATE(56),
    [sym__base_type] = STATE(16),
    [sym_primitive_type] = STATE(16),
    [sym__control_flow_statement] = STATE(54),
    [sym_goto_statement] = STATE(54),
    [sym_switch_statement] = STATE(54),
    [sym_return_statement] = STATE(54),
    [sym_group_expression] = STATE(57),
    [sym__literal] = STATE(55),
    [sym_string] = STATE(55),
    [sym_access_control] = STATE(58),
    [sym_variable_definition] = STATE(54),
    [sym_section_statement] = STATE(54),
    [sym_single_line_if_statement] = STATE(53),
    [sym__variable_statement] = STATE(54),
    [sym_assignment_expression] = STATE(59),
    [sym__collection_or_value] = STATE(60),
    [sym_character] = STATE(55),
    [anon_sym_i8] = ACTIONS(22),
    [anon_sym_return] = ACTIONS(66),
    [anon_sym_i64] = ACTIONS(22),
    [anon_sym_s32] = ACTIONS(22),
    [sym_binary] = ACTIONS(68),
    [anon_sym_while] = ACTIONS(70),
    [sym_null] = ACTIONS(72),
    [anon_sym_DQUOTE] = ACTIONS(74),
    [sym_readonly] = ACTIONS(32),
    [anon_sym_protected] = ACTIONS(76),
    [anon_sym_u16] = ACTIONS(22),
    [anon_sym_s8] = ACTIONS(22),
    [sym_double] = ACTIONS(72),
    [anon_sym_i16] = ACTIONS(22),
    [anon_sym_goto] = ACTIONS(78),
    [anon_sym_LBRACE] = ACTIONS(80),
    [anon_sym_private] = ACTIONS(76),
    [sym__comment] = ACTIONS(3),
    [anon_sym_publish] = ACTIONS(76),
    [anon_sym_u32] = ACTIONS(22),
    [anon_sym_s16] = ACTIONS(22),
    [anon_sym_f32] = ACTIONS(22),
    [anon_sym_LPAREN] = ACTIONS(82),
    [anon_sym_i32] = ACTIONS(22),
    [sym_oct] = ACTIONS(72),
    [sym_long] = ACTIONS(68),
    [sym_hex] = ACTIONS(68),
    [anon_sym_section] = ACTIONS(84),
    [anon_sym_if] = ACTIONS(86),
    [anon_sym_SQUOTE] = ACTIONS(88),
    [sym_identifier] = ACTIONS(90),
    [anon_sym_switch] = ACTIONS(92),
    [anon_sym_end] = ACTIONS(94),
    [anon_sym_u64] = ACTIONS(22),
    [anon_sym_u8] = ACTIONS(22),
    [sym_float] = ACTIONS(68),
    [anon_sym_f64] = ACTIONS(22),
    [sym_integer] = ACTIONS(72),
  },
  [23] = {
    [anon_sym_i8] = ACTIONS(96),
    [anon_sym_method] = ACTIONS(96),
    [anon_sym_private] = ACTIONS(96),
    [anon_sym_s32] = ACTIONS(96),
    [anon_sym_publish] = ACTIONS(96),
    [anon_sym_u32] = ACTIONS(96),
    [anon_sym_s16] = ACTIONS(96),
    [anon_sym_f32] = ACTIONS(96),
    [sym_is_external] = ACTIONS(96),
    [anon_sym_i32] = ACTIONS(96),
    [sym__comment] = ACTIONS(3),
    [anon_sym_function] = ACTIONS(96),
    [sym_readonly] = ACTIONS(96),
    [anon_sym_protected] = ACTIONS(96),
    [anon_sym_u16] = ACTIONS(96),
    [anon_sym_s8] = ACTIONS(96),
    [sym_is_declare] = ACTIONS(96),
    [anon_sym_enum] = ACTIONS(96),
    [anon_sym_i16] = ACTIONS(96),
    [sym_identifier] = ACTIONS(96),
    [anon_sym_end] = ACTIONS(96),
    [anon_sym_u64] = ACTIONS(96),
    [anon_sym_u8] = ACTIONS(96),
    [anon_sym_f64] = ACTIONS(96),
    [anon_sym_i64] = ACTIONS(96),
  },
  [24] = {
    [sym_identifier] = ACTIONS(98),
    [sym__comment] = ACTIONS(3),
  },
  [25] = {
    [sym_primitive_type] = STATE(16),
    [sym_is_method] = STATE(62),
    [sym_type] = STATE(26),
    [sym_is_function] = STATE(62),
    [sym__base_type] = STATE(16),
    [anon_sym_i8] = ACTIONS(22),
    [anon_sym_method] = ACTIONS(24),
    [anon_sym_s32] = ACTIONS(22),
    [sym__comment] = ACTIONS(3),
    [anon_sym_u32] = ACTIONS(22),
    [anon_sym_s16] = ACTIONS(22),
    [anon_sym_f32] = ACTIONS(22),
    [anon_sym_i32] = ACTIONS(22),
    [anon_sym_function] = ACTIONS(30),
    [sym_readonly] = ACTIONS(64),
    [anon_sym_u16] = ACTIONS(22),
    [anon_sym_s8] = ACTIONS(22),
    [anon_sym_i16] = ACTIONS(22),
    [sym_identifier] = ACTIONS(36),
    [anon_sym_u64] = ACTIONS(22),
    [anon_sym_u8] = ACTIONS(22),
    [anon_sym_f64] = ACTIONS(22),
    [anon_sym_i64] = ACTIONS(22),
  },
  [26] = {
    [sym_identifier] = ACTIONS(100),
    [sym__comment] = ACTIONS(3),
  },
  [27] = {
    [sym__enum_element] = STATE(65),
    [sym_identifier] = ACTIONS(102),
    [sym__comment] = ACTIONS(3),
  },
  [28] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(104),
  },
  [29] = {
    [sym_identifier] = ACTIONS(106),
    [anon_sym_STAR] = ACTIONS(106),
    [anon_sym_COMMA] = ACTIONS(106),
    [sym__comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(106),
    [anon_sym_DOT] = ACTIONS(106),
  },
  [30] = {
    [anon_sym_RBRACK] = ACTIONS(108),
    [sym__comment] = ACTIONS(3),
    [sym_integer] = ACTIONS(110),
  },
  [31] = {
    [aux_sym_type_repeat2] = STATE(68),
    [sym_array] = STATE(68),
    [sym_identifier] = ACTIONS(112),
    [sym__comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(56),
  },
  [32] = {
    [aux_sym_type_repeat2] = STATE(69),
    [aux_sym_type_repeat1] = STATE(70),
    [sym_pointer] = STATE(70),
    [sym_array] = STATE(69),
    [sym_identifier] = ACTIONS(112),
    [anon_sym_STAR] = ACTIONS(54),
    [sym__comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(56),
  },
  [33] = {
    [sym_primitive_type] = STATE(16),
    [sym_function_definition] = STATE(33),
    [sym_enum_definition] = STATE(33),
    [sym_variable_definition] = STATE(33),
    [sym_function_signature] = STATE(22),
    [sym_is_function] = STATE(19),
    [sym_is_method] = STATE(19),
    [sym_type] = STATE(20),
    [sym_declaration_definition] = STATE(33),
    [sym__definitions] = STATE(33),
    [aux_sym_module_definition_repeat1] = STATE(33),
    [sym_access_control] = STATE(21),
    [sym__base_type] = STATE(16),
    [anon_sym_i8] = ACTIONS(114),
    [anon_sym_method] = ACTIONS(117),
    [anon_sym_private] = ACTIONS(120),
    [anon_sym_s32] = ACTIONS(114),
    [anon_sym_publish] = ACTIONS(120),
    [anon_sym_u32] = ACTIONS(114),
    [anon_sym_s16] = ACTIONS(114),
    [anon_sym_f32] = ACTIONS(114),
    [sym_is_external] = ACTIONS(123),
    [anon_sym_i32] = ACTIONS(114),
    [sym__comment] = ACTIONS(3),
    [anon_sym_function] = ACTIONS(126),
    [sym_readonly] = ACTIONS(129),
    [anon_sym_protected] = ACTIONS(120),
    [anon_sym_u16] = ACTIONS(114),
    [anon_sym_s8] = ACTIONS(114),
    [sym_is_declare] = ACTIONS(123),
    [anon_sym_enum] = ACTIONS(132),
    [anon_sym_i16] = ACTIONS(114),
    [sym_identifier] = ACTIONS(135),
    [anon_sym_end] = ACTIONS(138),
    [anon_sym_u64] = ACTIONS(114),
    [anon_sym_u8] = ACTIONS(114),
    [anon_sym_f64] = ACTIONS(114),
    [anon_sym_i64] = ACTIONS(114),
  },
  [34] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(140),
  },
  [35] = {
    [sym__comment] = ACTIONS(3),
    [ts_builtin_sym_end] = ACTIONS(142),
    [anon_sym_module] = ACTIONS(142),
  },
  [36] = {
    [sym_parameter_list] = STATE(75),
    [sym_return_list] = STATE(76),
    [anon_sym_LPAREN] = ACTIONS(144),
    [anon_sym_returns] = ACTIONS(146),
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(148),
  },
  [37] = {
    [sym_static_assignment] = STATE(78),
    [anon_sym_i8] = ACTIONS(150),
    [anon_sym_s32] = ACTIONS(150),
    [sym_is_external] = ACTIONS(150),
    [anon_sym_function] = ACTIONS(150),
    [sym_readonly] = ACTIONS(150),
    [anon_sym_protected] = ACTIONS(150),
    [anon_sym_u16] = ACTIONS(150),
    [anon_sym_s8] = ACTIONS(150),
    [anon_sym_enum] = ACTIONS(150),
    [anon_sym_i16] = ACTIONS(150),
    [anon_sym_method] = ACTIONS(150),
    [anon_sym_private] = ACTIONS(150),
    [sym__comment] = ACTIONS(3),
    [anon_sym_publish] = ACTIONS(150),
    [anon_sym_u32] = ACTIONS(150),
    [anon_sym_s16] = ACTIONS(150),
    [anon_sym_f32] = ACTIONS(150),
    [anon_sym_i32] = ACTIONS(150),
    [anon_sym_COLON_EQ] = ACTIONS(152),
    [sym_is_declare] = ACTIONS(150),
    [anon_sym_DOT] = ACTIONS(154),
    [sym_identifier] = ACTIONS(150),
    [anon_sym_COMMA] = ACTIONS(154),
    [anon_sym_end] = ACTIONS(150),
    [anon_sym_u64] = ACTIONS(150),
    [anon_sym_u8] = ACTIONS(150),
    [anon_sym_f64] = ACTIONS(150),
    [anon_sym_RPAREN] = ACTIONS(154),
    [anon_sym_i64] = ACTIONS(150),
  },
  [38] = {
    [sym_primitive_type] = STATE(16),
    [sym_type] = STATE(79),
    [sym__base_type] = STATE(16),
    [anon_sym_i8] = ACTIONS(22),
    [anon_sym_s32] = ACTIONS(22),
    [sym__comment] = ACTIONS(3),
    [anon_sym_u32] = ACTIONS(22),
    [anon_sym_s16] = ACTIONS(22),
    [anon_sym_f32] = ACTIONS(22),
    [anon_sym_i32] = ACTIONS(22),
    [anon_sym_u16] = ACTIONS(22),
    [anon_sym_s8] = ACTIONS(22),
    [anon_sym_i16] = ACTIONS(22),
    [sym_identifier] = ACTIONS(36),
    [anon_sym_u64] = ACTIONS(22),
    [anon_sym_u8] = ACTIONS(22),
    [anon_sym_f64] = ACTIONS(22),
    [anon_sym_i64] = ACTIONS(22),
  },
  [39] = {
    [sym_identifier] = ACTIONS(156),
    [sym__comment] = ACTIONS(3),
  },
  [40] = {
    [sym_collection] = STATE(82),
    [sym__value] = STATE(55),
    [sym__number] = STATE(55),
    [sym_group_expression] = STATE(55),
    [sym__assignment_or_collection_or_value] = STATE(81),
    [sym__literal] = STATE(55),
    [sym_string] = STATE(55),
    [sym_assignment_expression] = STATE(81),
    [sym__collection_or_value] = STATE(82),
    [sym_character] = STATE(55),
    [anon_sym_LBRACE] = ACTIONS(80),
    [sym_double] = ACTIONS(72),
    [sym_binary] = ACTIONS(68),
    [sym__comment] = ACTIONS(3),
    [sym_oct] = ACTIONS(72),
    [anon_sym_SQUOTE] = ACTIONS(88),
    [sym_identifier] = ACTIONS(72),
    [anon_sym_LPAREN] = ACTIONS(82),
    [sym_long] = ACTIONS(68),
    [sym_null] = ACTIONS(72),
    [sym_integer] = ACTIONS(72),
    [anon_sym_DQUOTE] = ACTIONS(74),
    [sym_float] = ACTIONS(68),
    [sym_hex] = ACTIONS(68),
  },
  [41] = {
    [sym_group_expression] = STATE(83),
    [sym__comment] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(82),
  },
  [42] = {
    [aux_sym_string_repeat1] = STATE(85),
    [sym__comment] = ACTIONS(158),
    [anon_sym_DQUOTE] = ACTIONS(160),
    [aux_sym_string_token1] = ACTIONS(162),
  },
  [43] = {
    [anon_sym_i8] = ACTIONS(44),
    [anon_sym_s32] = ACTIONS(44),
    [sym__comment] = ACTIONS(3),
    [anon_sym_u32] = ACTIONS(44),
    [anon_sym_s16] = ACTIONS(44),
    [anon_sym_f32] = ACTIONS(44),
    [anon_sym_i32] = ACTIONS(44),
    [sym_readonly] = ACTIONS(44),
    [anon_sym_u16] = ACTIONS(44),
    [anon_sym_s8] = ACTIONS(44),
    [anon_sym_i16] = ACTIONS(44),
    [sym_identifier] = ACTIONS(44),
    [anon_sym_u64] = ACTIONS(44),
    [anon_sym_u8] = ACTIONS(44),
    [anon_sym_f64] = ACTIONS(44),
    [anon_sym_i64] = ACTIONS(44),
  },
  [44] = {
    [sym_identifier] = ACTIONS(164),
    [sym__comment] = ACTIONS(3),
  },
  [45] = {
    [sym__comma_list_assignment_or_collection_or_value] = STATE(87),
    [sym_collection] = STATE(82),
    [sym__value] = STATE(55),
    [sym__number] = STATE(55),
    [sym_group_expression] = STATE(55),
    [sym__assignment_or_collection_or_value] = STATE(88),
    [sym__literal] = STATE(55),
    [sym_string] = STATE(55),
    [sym_assignment_expression] = STATE(88),
    [sym__collection_or_value] = STATE(82),
    [sym_character] = STATE(55),
    [anon_sym_LBRACE] = ACTIONS(80),
    [sym_double] = ACTIONS(72),
    [sym_binary] = ACTIONS(68),
    [sym__comment] = ACTIONS(3),
    [sym_oct] = ACTIONS(72),
    [anon_sym_SQUOTE] = ACTIONS(88),
    [sym_identifier] = ACTIONS(72),
    [anon_sym_LPAREN] = ACTIONS(82),
    [sym_long] = ACTIONS(68),
    [sym_null] = ACTIONS(72),
    [sym_integer] = ACTIONS(72),
    [anon_sym_DQUOTE] = ACTIONS(74),
    [sym_float] = ACTIONS(68),
    [sym_hex] = ACTIONS(68),
  },
  [46] = {
    [sym_collection] = STATE(60),
    [sym__value] = STATE(90),
    [sym__number] = STATE(90),
    [sym_group_expression] = STATE(90),
    [sym__literal] = STATE(90),
    [sym_string] = STATE(90),
    [sym_assignment_expression] = STATE(91),
    [sym_unary_op] = STATE(92),
    [sym__collection_or_value] = STATE(60),
    [sym_character] = STATE(90),
    [anon_sym_LBRACE] = ACTIONS(80),
    [sym_binary] = ACTIONS(166),
    [sym__comment] = ACTIONS(3),
    [sym_oct] = ACTIONS(168),
    [sym_hex] = ACTIONS(166),
    [sym_long] = ACTIONS(166),
    [anon_sym_LPAREN] = ACTIONS(82),
    [anon_sym_AMP] = ACTIONS(170),
    [sym_null] = ACTIONS(168),
    [anon_sym_TILDE] = ACTIONS(170),
    [anon_sym_DQUOTE] = ACTIONS(74),
    [sym_double] = ACTIONS(168),
    [anon_sym_DASH] = ACTIONS(172),
    [anon_sym_SQUOTE] = ACTIONS(88),
    [anon_sym_BANG] = ACTIONS(170),
    [anon_sym_STAR] = ACTIONS(170),
    [sym_identifier] = ACTIONS(168),
    [sym_integer] = ACTIONS(168),
    [sym_float] = ACTIONS(166),
  },
  [47] = {
    [sym_identifier] = ACTIONS(174),
    [sym__comment] = ACTIONS(3),
  },
  [48] = {
    [sym_group_expression] = STATE(95),
    [sym__comment] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(176),
  },
  [49] = {
    [sym__escape_sequence] = STATE(96),
    [anon_sym_BSLASHb] = ACTIONS(178),
    [anon_sym_BSLASHv] = ACTIONS(178),
    [anon_sym_BSLASHa] = ACTIONS(178),
    [aux_sym_character_token1] = ACTIONS(180),
    [anon_sym_BSLASHf] = ACTIONS(178),
    [sym__comment] = ACTIONS(3),
    [anon_sym_BSLASH_BSLASH] = ACTIONS(178),
    [anon_sym_BSLASHn] = ACTIONS(178),
    [anon_sym_BSLASHt] = ACTIONS(178),
    [anon_sym_BSLASH0] = ACTIONS(178),
    [anon_sym_BSLASHr] = ACTIONS(178),
  },
  [50] = {
    [anon_sym_PIPE_EQ] = ACTIONS(182),
    [anon_sym_SLASH_EQ] = ACTIONS(182),
    [anon_sym_GT_GT_EQ] = ACTIONS(182),
    [sym__comment] = ACTIONS(3),
    [anon_sym_STAR_EQ] = ACTIONS(182),
    [anon_sym_COLON_EQ] = ACTIONS(182),
    [anon_sym_DASH_DASH] = ACTIONS(184),
    [anon_sym_LBRACK] = ACTIONS(186),
    [anon_sym_AMP_EQ] = ACTIONS(182),
    [anon_sym_CARET_EQ] = ACTIONS(182),
    [anon_sym_PLUS_PLUS] = ACTIONS(182),
    [anon_sym_DASH_EQ] = ACTIONS(182),
    [sym_identifier] = ACTIONS(186),
    [anon_sym_STAR] = ACTIONS(188),
    [anon_sym_PERCENT_EQ] = ACTIONS(182),
    [anon_sym_LT_LT_EQ] = ACTIONS(182),
    [anon_sym_PLUS_EQ] = ACTIONS(182),
  },
  [51] = {
    [sym_group_expression] = STATE(97),
    [sym__comment] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(82),
  },
  [52] = {
    [anon_sym_function] = ACTIONS(190),
    [anon_sym_method] = ACTIONS(192),
    [sym__comment] = ACTIONS(3),
  },
  [53] = {
    [aux_sym_function_definition_repeat1] = STATE(100),
    [sym_end_method] = STATE(101),
    [sym_end_function] = STATE(101),
    [sym_type] = STATE(20),
    [sym__statement] = STATE(100),
    [sym_if_statement] = STATE(54),
    [sym_while_statement] = STATE(54),
    [sym_expression_statement] = STATE(54),
    [sym_collection] = STATE(60),
    [sym__value] = STATE(55),
    [sym__number] = STATE(55),
    [sym__end_function] = STATE(101),
    [sym__base_type] = STATE(16),
    [sym_primitive_type] = STATE(16),
    [sym__control_flow_statement] = STATE(54),
    [sym_goto_statement] = STATE(54),
    [sym_switch_statement] = STATE(54),
    [sym_return_statement] = STATE(54),
    [sym_group_expression] = STATE(57),
    [sym__literal] = STATE(55),
    [sym_string] = STATE(55),
    [sym_access_control] = STATE(58),
    [sym_variable_definition] = STATE(54),
    [sym_section_statement] = STATE(54),
    [sym_single_line_if_statement] = STATE(100),
    [sym__variable_statement] = STATE(54),
    [sym_assignment_expression] = STATE(59),
    [sym__collection_or_value] = STATE(60),
    [sym_character] = STATE(55),
    [anon_sym_i8] = ACTIONS(22),
    [anon_sym_return] = ACTIONS(66),
    [anon_sym_i64] = ACTIONS(22),
    [anon_sym_s32] = ACTIONS(22),
    [sym_binary] = ACTIONS(68),
    [anon_sym_while] = ACTIONS(70),
    [sym_null] = ACTIONS(72),
    [anon_sym_DQUOTE] = ACTIONS(74),
    [sym_readonly] = ACTIONS(32),
    [anon_sym_protected] = ACTIONS(76),
    [anon_sym_u16] = ACTIONS(22),
    [anon_sym_s8] = ACTIONS(22),
    [sym_double] = ACTIONS(72),
    [anon_sym_i16] = ACTIONS(22),
    [anon_sym_goto] = ACTIONS(78),
    [anon_sym_LBRACE] = ACTIONS(80),
    [anon_sym_private] = ACTIONS(76),
    [sym__comment] = ACTIONS(3),
    [anon_sym_publish] = ACTIONS(76),
    [anon_sym_u32] = ACTIONS(22),
    [anon_sym_s16] = ACTIONS(22),
    [anon_sym_f32] = ACTIONS(22),
    [anon_sym_LPAREN] = ACTIONS(82),
    [anon_sym_i32] = ACTIONS(22),
    [sym_oct] = ACTIONS(72),
    [sym_long] = ACTIONS(68),
    [sym_hex] = ACTIONS(68),
    [anon_sym_section] = ACTIONS(84),
    [anon_sym_if] = ACTIONS(86),
    [anon_sym_SQUOTE] = ACTIONS(88),
    [sym_identifier] = ACTIONS(90),
    [anon_sym_switch] = ACTIONS(92),
    [anon_sym_end] = ACTIONS(94),
    [anon_sym_u64] = ACTIONS(22),
    [anon_sym_u8] = ACTIONS(22),
    [sym_float] = ACTIONS(68),
    [anon_sym_f64] = ACTIONS(22),
    [sym_integer] = ACTIONS(72),
  },
  [54] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(194),
  },
  [55] = {
    [sym_assignment_post_op] = STATE(104),
    [anon_sym_PIPE_EQ] = ACTIONS(196),
    [anon_sym_SLASH_EQ] = ACTIONS(196),
    [anon_sym_GT_GT_EQ] = ACTIONS(196),
    [sym__comment] = ACTIONS(3),
    [anon_sym_STAR_EQ] = ACTIONS(196),
    [anon_sym_COLON_EQ] = ACTIONS(196),
    [anon_sym_DASH_DASH] = ACTIONS(198),
    [anon_sym_AMP_EQ] = ACTIONS(196),
    [anon_sym_PLUS_PLUS] = ACTIONS(200),
    [anon_sym_CARET_EQ] = ACTIONS(196),
    [anon_sym_DASH_EQ] = ACTIONS(196),
    [anon_sym_RBRACE] = ACTIONS(196),
    [anon_sym_DOT] = ACTIONS(196),
    [anon_sym_PERCENT_EQ] = ACTIONS(196),
    [anon_sym_LT_LT_EQ] = ACTIONS(196),
    [anon_sym_COMMA] = ACTIONS(196),
    [anon_sym_PLUS_EQ] = ACTIONS(196),
  },
  [56] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(202),
  },
  [57] = {
    [anon_sym_PIPE_EQ] = ACTIONS(182),
    [anon_sym_SLASH_EQ] = ACTIONS(182),
    [anon_sym_GT_GT_EQ] = ACTIONS(182),
    [sym__comment] = ACTIONS(3),
    [anon_sym_STAR_EQ] = ACTIONS(182),
    [anon_sym_DASH_DASH] = ACTIONS(184),
    [anon_sym_COLON_EQ] = ACTIONS(182),
    [anon_sym_AMP_EQ] = ACTIONS(182),
    [anon_sym_PLUS_PLUS] = ACTIONS(182),
    [anon_sym_CARET_EQ] = ACTIONS(182),
    [anon_sym_DASH_EQ] = ACTIONS(182),
    [anon_sym_DOT] = ACTIONS(204),
    [anon_sym_PERCENT_EQ] = ACTIONS(182),
    [anon_sym_LT_LT_EQ] = ACTIONS(182),
    [anon_sym_PLUS_EQ] = ACTIONS(182),
  },
  [58] = {
    [sym_primitive_type] = STATE(16),
    [sym_type] = STATE(26),
    [sym__base_type] = STATE(16),
    [anon_sym_i8] = ACTIONS(22),
    [anon_sym_s32] = ACTIONS(22),
    [sym__comment] = ACTIONS(3),
    [anon_sym_u32] = ACTIONS(22),
    [anon_sym_s16] = ACTIONS(22),
    [anon_sym_f32] = ACTIONS(22),
    [anon_sym_i32] = ACTIONS(22),
    [sym_readonly] = ACTIONS(64),
    [anon_sym_u16] = ACTIONS(22),
    [anon_sym_s8] = ACTIONS(22),
    [anon_sym_i16] = ACTIONS(22),
    [sym_identifier] = ACTIONS(36),
    [anon_sym_u64] = ACTIONS(22),
    [anon_sym_u8] = ACTIONS(22),
    [anon_sym_f64] = ACTIONS(22),
    [anon_sym_i64] = ACTIONS(22),
  },
  [59] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(204),
  },
  [60] = {
    [sym_assignment_op] = STATE(107),
    [anon_sym_CARET_EQ] = ACTIONS(206),
    [anon_sym_DASH_EQ] = ACTIONS(206),
    [anon_sym_PIPE_EQ] = ACTIONS(206),
    [anon_sym_SLASH_EQ] = ACTIONS(206),
    [anon_sym_GT_GT_EQ] = ACTIONS(206),
    [sym__comment] = ACTIONS(3),
    [anon_sym_STAR_EQ] = ACTIONS(206),
    [anon_sym_PERCENT_EQ] = ACTIONS(206),
    [anon_sym_LT_LT_EQ] = ACTIONS(206),
    [anon_sym_COLON_EQ] = ACTIONS(206),
    [anon_sym_PLUS_EQ] = ACTIONS(206),
    [anon_sym_AMP_EQ] = ACTIONS(206),
  },
  [61] = {
    [sym_parameter_list] = STATE(109),
    [sym_return_list] = STATE(110),
    [anon_sym_LPAREN] = ACTIONS(144),
    [anon_sym_returns] = ACTIONS(146),
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(208),
  },
  [62] = {
    [sym_identifier] = ACTIONS(210),
    [sym__comment] = ACTIONS(3),
  },
  [63] = {
    [sym_static_assignment] = STATE(112),
    [anon_sym_i8] = ACTIONS(212),
    [anon_sym_s32] = ACTIONS(212),
    [sym_is_external] = ACTIONS(212),
    [anon_sym_function] = ACTIONS(212),
    [sym_readonly] = ACTIONS(212),
    [anon_sym_protected] = ACTIONS(212),
    [anon_sym_u16] = ACTIONS(212),
    [anon_sym_s8] = ACTIONS(212),
    [anon_sym_enum] = ACTIONS(212),
    [anon_sym_i16] = ACTIONS(212),
    [anon_sym_method] = ACTIONS(212),
    [anon_sym_private] = ACTIONS(212),
    [sym__comment] = ACTIONS(3),
    [anon_sym_publish] = ACTIONS(212),
    [anon_sym_u32] = ACTIONS(212),
    [anon_sym_s16] = ACTIONS(212),
    [anon_sym_f32] = ACTIONS(212),
    [anon_sym_i32] = ACTIONS(212),
    [anon_sym_COLON_EQ] = ACTIONS(152),
    [sym_is_declare] = ACTIONS(212),
    [anon_sym_DOT] = ACTIONS(214),
    [sym_identifier] = ACTIONS(212),
    [anon_sym_COMMA] = ACTIONS(214),
    [anon_sym_end] = ACTIONS(212),
    [anon_sym_u64] = ACTIONS(212),
    [anon_sym_u8] = ACTIONS(212),
    [anon_sym_f64] = ACTIONS(212),
    [anon_sym_RPAREN] = ACTIONS(214),
    [anon_sym_i64] = ACTIONS(212),
  },
  [64] = {
    [sym_static_assignment] = STATE(113),
    [anon_sym_COMMA] = ACTIONS(216),
    [anon_sym_COLON_EQ] = ACTIONS(152),
    [sym__comment] = ACTIONS(3),
    [anon_sym_RPAREN] = ACTIONS(216),
  },
  [65] = {
    [aux_sym_enum_definition_repeat1] = STATE(116),
    [sym__comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(218),
    [anon_sym_RPAREN] = ACTIONS(220),
  },
  [66] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_RBRACK] = ACTIONS(222),
  },
  [67] = {
    [sym_identifier] = ACTIONS(224),
    [anon_sym_COMMA] = ACTIONS(224),
    [sym__comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(224),
    [anon_sym_DOT] = ACTIONS(224),
  },
  [68] = {
    [aux_sym_type_repeat2] = STATE(68),
    [sym_array] = STATE(68),
    [sym_identifier] = ACTIONS(226),
    [sym__comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(228),
  },
  [69] = {
    [aux_sym_type_repeat2] = STATE(68),
    [sym_array] = STATE(68),
    [sym_identifier] = ACTIONS(231),
    [sym__comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(56),
  },
  [70] = {
    [aux_sym_type_repeat1] = STATE(70),
    [sym_pointer] = STATE(70),
    [sym_identifier] = ACTIONS(233),
    [anon_sym_STAR] = ACTIONS(235),
    [sym__comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(233),
  },
  [71] = {
    [sym__comment] = ACTIONS(3),
    [ts_builtin_sym_end] = ACTIONS(238),
    [anon_sym_module] = ACTIONS(238),
  },
  [72] = {
    [anon_sym_i8] = ACTIONS(240),
    [anon_sym_return] = ACTIONS(240),
    [sym_float] = ACTIONS(242),
    [anon_sym_s32] = ACTIONS(240),
    [sym_binary] = ACTIONS(242),
    [anon_sym_while] = ACTIONS(240),
    [sym_null] = ACTIONS(240),
    [anon_sym_DQUOTE] = ACTIONS(242),
    [sym_readonly] = ACTIONS(240),
    [anon_sym_protected] = ACTIONS(240),
    [anon_sym_u16] = ACTIONS(240),
    [anon_sym_s8] = ACTIONS(240),
    [sym_double] = ACTIONS(240),
    [anon_sym_i16] = ACTIONS(240),
    [anon_sym_goto] = ACTIONS(240),
    [anon_sym_LBRACE] = ACTIONS(242),
    [anon_sym_private] = ACTIONS(240),
    [sym__comment] = ACTIONS(3),
    [anon_sym_publish] = ACTIONS(240),
    [anon_sym_u32] = ACTIONS(240),
    [anon_sym_s16] = ACTIONS(240),
    [anon_sym_f32] = ACTIONS(240),
    [anon_sym_LPAREN] = ACTIONS(242),
    [anon_sym_i32] = ACTIONS(240),
    [sym_oct] = ACTIONS(240),
    [sym_long] = ACTIONS(242),
    [sym_hex] = ACTIONS(242),
    [anon_sym_section] = ACTIONS(240),
    [anon_sym_if] = ACTIONS(240),
    [anon_sym_SQUOTE] = ACTIONS(242),
    [anon_sym_switch] = ACTIONS(240),
    [sym_identifier] = ACTIONS(240),
    [anon_sym_end] = ACTIONS(240),
    [anon_sym_u64] = ACTIONS(240),
    [anon_sym_u8] = ACTIONS(240),
    [anon_sym_f64] = ACTIONS(240),
    [sym_integer] = ACTIONS(240),
    [anon_sym_i64] = ACTIONS(240),
  },
  [73] = {
    [sym_primitive_type] = STATE(16),
    [sym_type] = STATE(20),
    [sym_variable_definition] = STATE(119),
    [sym__comma_list_variables] = STATE(120),
    [sym_access_control] = STATE(58),
    [sym__base_type] = STATE(16),
    [anon_sym_i8] = ACTIONS(22),
    [anon_sym_private] = ACTIONS(76),
    [anon_sym_s32] = ACTIONS(22),
    [anon_sym_publish] = ACTIONS(76),
    [anon_sym_u32] = ACTIONS(22),
    [anon_sym_s16] = ACTIONS(22),
    [anon_sym_f32] = ACTIONS(22),
    [sym__comment] = ACTIONS(3),
    [anon_sym_i32] = ACTIONS(22),
    [sym_readonly] = ACTIONS(32),
    [anon_sym_protected] = ACTIONS(76),
    [anon_sym_u16] = ACTIONS(22),
    [anon_sym_s8] = ACTIONS(22),
    [anon_sym_i16] = ACTIONS(22),
    [sym_identifier] = ACTIONS(36),
    [anon_sym_u64] = ACTIONS(22),
    [anon_sym_u8] = ACTIONS(22),
    [anon_sym_f64] = ACTIONS(22),
    [anon_sym_RPAREN] = ACTIONS(244),
    [anon_sym_i64] = ACTIONS(22),
  },
  [74] = {
    [sym_primitive_type] = STATE(123),
    [sym__comma_list_types] = STATE(121),
    [sym_type] = STATE(122),
    [sym__base_type] = STATE(123),
    [anon_sym_i8] = ACTIONS(22),
    [anon_sym_s32] = ACTIONS(22),
    [sym__comment] = ACTIONS(3),
    [anon_sym_u32] = ACTIONS(22),
    [anon_sym_s16] = ACTIONS(22),
    [anon_sym_f32] = ACTIONS(22),
    [anon_sym_i32] = ACTIONS(22),
    [anon_sym_u16] = ACTIONS(22),
    [anon_sym_s8] = ACTIONS(22),
    [anon_sym_i16] = ACTIONS(22),
    [sym_identifier] = ACTIONS(246),
    [anon_sym_u64] = ACTIONS(22),
    [anon_sym_u8] = ACTIONS(22),
    [anon_sym_f64] = ACTIONS(22),
    [anon_sym_i64] = ACTIONS(22),
  },
  [75] = {
    [sym_return_list] = STATE(125),
    [anon_sym_returns] = ACTIONS(146),
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(248),
  },
  [76] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(248),
  },
  [77] = {
    [sym_collection] = STATE(126),
    [sym__value] = STATE(126),
    [sym__number] = STATE(126),
    [sym_group_expression] = STATE(126),
    [sym__literal] = STATE(126),
    [sym_string] = STATE(126),
    [sym__collection_or_value] = STATE(126),
    [sym_character] = STATE(126),
    [anon_sym_LBRACE] = ACTIONS(80),
    [sym_double] = ACTIONS(250),
    [sym_binary] = ACTIONS(252),
    [sym__comment] = ACTIONS(3),
    [sym_oct] = ACTIONS(250),
    [anon_sym_SQUOTE] = ACTIONS(88),
    [sym_identifier] = ACTIONS(250),
    [anon_sym_LPAREN] = ACTIONS(82),
    [sym_long] = ACTIONS(252),
    [sym_null] = ACTIONS(250),
    [sym_integer] = ACTIONS(250),
    [anon_sym_DQUOTE] = ACTIONS(74),
    [sym_float] = ACTIONS(252),
    [sym_hex] = ACTIONS(252),
  },
  [78] = {
    [anon_sym_i8] = ACTIONS(212),
    [anon_sym_method] = ACTIONS(212),
    [anon_sym_private] = ACTIONS(212),
    [anon_sym_s32] = ACTIONS(212),
    [anon_sym_publish] = ACTIONS(212),
    [anon_sym_u32] = ACTIONS(212),
    [anon_sym_s16] = ACTIONS(212),
    [anon_sym_f32] = ACTIONS(212),
    [sym_is_external] = ACTIONS(212),
    [anon_sym_i32] = ACTIONS(212),
    [sym__comment] = ACTIONS(3),
    [anon_sym_function] = ACTIONS(212),
    [sym_readonly] = ACTIONS(212),
    [anon_sym_protected] = ACTIONS(212),
    [anon_sym_u16] = ACTIONS(212),
    [anon_sym_s8] = ACTIONS(212),
    [sym_is_declare] = ACTIONS(212),
    [anon_sym_enum] = ACTIONS(212),
    [anon_sym_i16] = ACTIONS(212),
    [anon_sym_DOT] = ACTIONS(214),
    [sym_identifier] = ACTIONS(212),
    [anon_sym_COMMA] = ACTIONS(214),
    [anon_sym_end] = ACTIONS(212),
    [anon_sym_u64] = ACTIONS(212),
    [anon_sym_u8] = ACTIONS(212),
    [anon_sym_f64] = ACTIONS(212),
    [anon_sym_RPAREN] = ACTIONS(214),
    [anon_sym_i64] = ACTIONS(212),
  },
  [79] = {
    [sym_identifier] = ACTIONS(254),
    [sym__comment] = ACTIONS(3),
  },
  [80] = {
    [sym_parameter_list] = STATE(128),
    [sym_return_list] = STATE(125),
    [anon_sym_LPAREN] = ACTIONS(144),
    [anon_sym_returns] = ACTIONS(146),
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(248),
  },
  [81] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(256),
  },
  [82] = {
    [sym_assignment_op] = STATE(107),
    [anon_sym_PIPE_EQ] = ACTIONS(206),
    [anon_sym_SLASH_EQ] = ACTIONS(206),
    [anon_sym_GT_GT_EQ] = ACTIONS(206),
    [sym__comment] = ACTIONS(3),
    [anon_sym_STAR_EQ] = ACTIONS(206),
    [anon_sym_COLON_EQ] = ACTIONS(206),
    [anon_sym_AMP_EQ] = ACTIONS(206),
    [anon_sym_CARET_EQ] = ACTIONS(206),
    [anon_sym_DASH_EQ] = ACTIONS(206),
    [anon_sym_RBRACE] = ACTIONS(258),
    [anon_sym_DOT] = ACTIONS(258),
    [anon_sym_PERCENT_EQ] = ACTIONS(206),
    [anon_sym_LT_LT_EQ] = ACTIONS(206),
    [anon_sym_COMMA] = ACTIONS(258),
    [anon_sym_PLUS_EQ] = ACTIONS(206),
  },
  [83] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(260),
  },
  [84] = {
    [anon_sym_PLUS] = ACTIONS(262),
    [anon_sym_s32] = ACTIONS(262),
    [anon_sym_PIPE_PIPE] = ACTIONS(264),
    [anon_sym_LT_LT] = ACTIONS(262),
    [anon_sym_LT_EQ] = ACTIONS(264),
    [anon_sym_function] = ACTIONS(262),
    [sym_readonly] = ACTIONS(262),
    [anon_sym_PLUS_PLUS] = ACTIONS(264),
    [anon_sym_protected] = ACTIONS(262),
    [anon_sym_s8] = ACTIONS(262),
    [anon_sym_enum] = ACTIONS(262),
    [anon_sym_SLASH] = ACTIONS(262),
    [anon_sym_STAR] = ACTIONS(262),
    [anon_sym_GT_GT] = ACTIONS(262),
    [anon_sym_PLUS_EQ] = ACTIONS(264),
    [anon_sym_BANG_EQ] = ACTIONS(264),
    [anon_sym_method] = ACTIONS(262),
    [anon_sym_private] = ACTIONS(262),
    [anon_sym_SLASH_EQ] = ACTIONS(264),
    [anon_sym_publish] = ACTIONS(262),
    [anon_sym_s16] = ACTIONS(262),
    [anon_sym_COLON_EQ] = ACTIONS(264),
    [sym_is_declare] = ACTIONS(262),
    [anon_sym_DASH_EQ] = ACTIONS(264),
    [anon_sym_PERCENT] = ACTIONS(262),
    [anon_sym_PERCENT_EQ] = ACTIONS(264),
    [anon_sym_end] = ACTIONS(262),
    [anon_sym_u8] = ACTIONS(262),
    [anon_sym_RPAREN] = ACTIONS(264),
    [anon_sym_i8] = ACTIONS(262),
    [sym_is_external] = ACTIONS(262),
    [anon_sym_STAR_EQ] = ACTIONS(264),
    [anon_sym_PIPE] = ACTIONS(262),
    [anon_sym_DASH_DASH] = ACTIONS(262),
    [anon_sym_AMP_EQ] = ACTIONS(264),
    [anon_sym_CARET_EQ] = ACTIONS(264),
    [anon_sym_u16] = ACTIONS(262),
    [anon_sym_i16] = ACTIONS(262),
    [anon_sym_DASH] = ACTIONS(262),
    [anon_sym_EQ_EQ] = ACTIONS(264),
    [anon_sym_CARET] = ACTIONS(262),
    [anon_sym_LT] = ACTIONS(262),
    [anon_sym_PIPE_EQ] = ACTIONS(264),
    [sym__comment] = ACTIONS(3),
    [anon_sym_GT_GT_EQ] = ACTIONS(264),
    [anon_sym_u32] = ACTIONS(262),
    [anon_sym_f32] = ACTIONS(262),
    [anon_sym_i32] = ACTIONS(262),
    [anon_sym_AMP] = ACTIONS(262),
    [anon_sym_AMP_AMP] = ACTIONS(264),
    [anon_sym_GT] = ACTIONS(262),
    [anon_sym_GT_EQ] = ACTIONS(264),
    [anon_sym_RBRACE] = ACTIONS(264),
    [anon_sym_DOT] = ACTIONS(264),
    [sym_identifier] = ACTIONS(262),
    [anon_sym_COMMA] = ACTIONS(264),
    [anon_sym_LT_LT_EQ] = ACTIONS(264),
    [anon_sym_u64] = ACTIONS(262),
    [anon_sym_f64] = ACTIONS(262),
    [anon_sym_i64] = ACTIONS(262),
  },
  [85] = {
    [aux_sym_string_repeat1] = STATE(131),
    [sym__comment] = ACTIONS(158),
    [anon_sym_DQUOTE] = ACTIONS(266),
    [aux_sym_string_token1] = ACTIONS(268),
  },
  [86] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(270),
  },
  [87] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_RBRACE] = ACTIONS(272),
  },
  [88] = {
    [aux_sym__comma_list_assignment_or_collection_or_value_repeat1] = STATE(134),
    [sym__comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(274),
    [anon_sym_RBRACE] = ACTIONS(276),
  },
  [89] = {
    [sym_double] = ACTIONS(278),
    [sym_binary] = ACTIONS(280),
    [sym__comment] = ACTIONS(3),
    [sym_oct] = ACTIONS(278),
    [anon_sym_SQUOTE] = ACTIONS(280),
    [sym_identifier] = ACTIONS(278),
    [anon_sym_LPAREN] = ACTIONS(280),
    [sym_long] = ACTIONS(280),
    [sym_null] = ACTIONS(278),
    [sym_integer] = ACTIONS(278),
    [anon_sym_DQUOTE] = ACTIONS(280),
    [sym_float] = ACTIONS(280),
    [sym_hex] = ACTIONS(280),
  },
  [90] = {
    [sym_binary_op] = STATE(137),
    [sym_assignment_post_op] = STATE(104),
    [anon_sym_PLUS] = ACTIONS(282),
    [anon_sym_PIPE_PIPE] = ACTIONS(284),
    [anon_sym_STAR_EQ] = ACTIONS(196),
    [anon_sym_LT_LT] = ACTIONS(282),
    [anon_sym_PIPE] = ACTIONS(282),
    [anon_sym_LT_EQ] = ACTIONS(284),
    [anon_sym_DASH_DASH] = ACTIONS(198),
    [anon_sym_AMP_EQ] = ACTIONS(196),
    [anon_sym_PLUS_PLUS] = ACTIONS(200),
    [anon_sym_CARET_EQ] = ACTIONS(196),
    [anon_sym_DASH] = ACTIONS(282),
    [anon_sym_SLASH] = ACTIONS(282),
    [anon_sym_STAR] = ACTIONS(282),
    [anon_sym_GT_GT] = ACTIONS(282),
    [anon_sym_EQ_EQ] = ACTIONS(284),
    [anon_sym_PLUS_EQ] = ACTIONS(196),
    [anon_sym_CARET] = ACTIONS(282),
    [anon_sym_BANG_EQ] = ACTIONS(284),
    [anon_sym_LT] = ACTIONS(282),
    [anon_sym_PIPE_EQ] = ACTIONS(196),
    [anon_sym_SLASH_EQ] = ACTIONS(196),
    [anon_sym_GT_GT_EQ] = ACTIONS(196),
    [sym__comment] = ACTIONS(3),
    [anon_sym_AMP] = ACTIONS(282),
    [anon_sym_COLON_EQ] = ACTIONS(196),
    [anon_sym_AMP_AMP] = ACTIONS(284),
    [anon_sym_DASH_EQ] = ACTIONS(196),
    [anon_sym_GT] = ACTIONS(282),
    [anon_sym_PERCENT] = ACTIONS(282),
    [anon_sym_GT_EQ] = ACTIONS(284),
    [anon_sym_PERCENT_EQ] = ACTIONS(196),
    [anon_sym_LT_LT_EQ] = ACTIONS(196),
    [anon_sym_RPAREN] = ACTIONS(286),
  },
  [91] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_RPAREN] = ACTIONS(286),
  },
  [92] = {
    [sym__literal] = STATE(138),
    [sym_string] = STATE(138),
    [sym__value] = STATE(138),
    [sym__number] = STATE(138),
    [sym_group_expression] = STATE(138),
    [sym_character] = STATE(138),
    [sym_double] = ACTIONS(288),
    [sym_binary] = ACTIONS(290),
    [sym__comment] = ACTIONS(3),
    [sym_oct] = ACTIONS(288),
    [anon_sym_SQUOTE] = ACTIONS(88),
    [sym_identifier] = ACTIONS(288),
    [anon_sym_LPAREN] = ACTIONS(82),
    [sym_long] = ACTIONS(290),
    [sym_null] = ACTIONS(288),
    [sym_integer] = ACTIONS(288),
    [anon_sym_DQUOTE] = ACTIONS(74),
    [sym_float] = ACTIONS(290),
    [sym_hex] = ACTIONS(290),
  },
  [93] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(292),
  },
  [94] = {
    [sym_collection] = STATE(60),
    [sym__value] = STATE(139),
    [sym__number] = STATE(139),
    [sym_group_expression] = STATE(139),
    [sym__literal] = STATE(139),
    [sym_string] = STATE(139),
    [sym_assignment_expression] = STATE(140),
    [sym_unary_op] = STATE(141),
    [sym__collection_or_value] = STATE(60),
    [sym_character] = STATE(139),
    [anon_sym_LBRACE] = ACTIONS(80),
    [sym_binary] = ACTIONS(294),
    [sym__comment] = ACTIONS(3),
    [sym_oct] = ACTIONS(296),
    [sym_hex] = ACTIONS(294),
    [sym_long] = ACTIONS(294),
    [anon_sym_LPAREN] = ACTIONS(82),
    [anon_sym_AMP] = ACTIONS(170),
    [sym_null] = ACTIONS(296),
    [anon_sym_TILDE] = ACTIONS(170),
    [anon_sym_DQUOTE] = ACTIONS(74),
    [sym_double] = ACTIONS(296),
    [anon_sym_DASH] = ACTIONS(172),
    [anon_sym_SQUOTE] = ACTIONS(88),
    [anon_sym_BANG] = ACTIONS(170),
    [anon_sym_STAR] = ACTIONS(170),
    [sym_identifier] = ACTIONS(296),
    [sym_integer] = ACTIONS(296),
    [sym_float] = ACTIONS(294),
  },
  [95] = {
    [sym_primitive_type] = STATE(16),
    [sym__control_flow_statement] = STATE(54),
    [sym_goto_statement] = STATE(54),
    [sym_switch_statement] = STATE(54),
    [sym__base_type] = STATE(16),
    [sym_return_statement] = STATE(54),
    [sym_group_expression] = STATE(57),
    [sym__literal] = STATE(55),
    [sym_type] = STATE(20),
    [sym_string] = STATE(55),
    [sym__statement] = STATE(143),
    [sym_if_statement] = STATE(54),
    [sym_access_control] = STATE(58),
    [sym_while_statement] = STATE(54),
    [sym_expression_statement] = STATE(54),
    [sym_variable_definition] = STATE(54),
    [sym__value] = STATE(55),
    [sym_collection] = STATE(60),
    [sym__number] = STATE(55),
    [sym_section_statement] = STATE(54),
    [sym_single_line_if_statement] = STATE(143),
    [sym__variable_statement] = STATE(54),
    [sym_assignment_expression] = STATE(59),
    [sym__collection_or_value] = STATE(60),
    [sym_character] = STATE(55),
    [anon_sym_i8] = ACTIONS(22),
    [anon_sym_return] = ACTIONS(66),
    [anon_sym_i64] = ACTIONS(22),
    [anon_sym_s32] = ACTIONS(22),
    [sym_binary] = ACTIONS(68),
    [anon_sym_while] = ACTIONS(70),
    [sym_null] = ACTIONS(72),
    [anon_sym_DQUOTE] = ACTIONS(74),
    [sym_readonly] = ACTIONS(32),
    [anon_sym_protected] = ACTIONS(76),
    [anon_sym_u16] = ACTIONS(22),
    [anon_sym_s8] = ACTIONS(22),
    [sym_double] = ACTIONS(72),
    [anon_sym_i16] = ACTIONS(22),
    [anon_sym_goto] = ACTIONS(78),
    [anon_sym_LBRACE] = ACTIONS(80),
    [anon_sym_private] = ACTIONS(76),
    [sym__comment] = ACTIONS(3),
    [anon_sym_publish] = ACTIONS(76),
    [anon_sym_u32] = ACTIONS(22),
    [anon_sym_s16] = ACTIONS(22),
    [anon_sym_f32] = ACTIONS(22),
    [anon_sym_LPAREN] = ACTIONS(82),
    [anon_sym_i32] = ACTIONS(22),
    [sym_oct] = ACTIONS(72),
    [sym_long] = ACTIONS(68),
    [sym_hex] = ACTIONS(68),
    [anon_sym_section] = ACTIONS(84),
    [anon_sym_if] = ACTIONS(86),
    [anon_sym_SQUOTE] = ACTIONS(88),
    [sym_identifier] = ACTIONS(90),
    [anon_sym_switch] = ACTIONS(92),
    [anon_sym_DOT] = ACTIONS(298),
    [anon_sym_u64] = ACTIONS(22),
    [anon_sym_u8] = ACTIONS(22),
    [sym_float] = ACTIONS(68),
    [anon_sym_f64] = ACTIONS(22),
    [sym_integer] = ACTIONS(72),
  },
  [96] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_SQUOTE] = ACTIONS(300),
  },
  [97] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(302),
  },
  [98] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(304),
  },
  [99] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(306),
  },
  [100] = {
    [sym_primitive_type] = STATE(16),
    [sym__control_flow_statement] = STATE(54),
    [sym_goto_statement] = STATE(54),
    [sym_switch_statement] = STATE(54),
    [aux_sym_function_definition_repeat1] = STATE(100),
    [sym_return_statement] = STATE(54),
    [sym_group_expression] = STATE(57),
    [sym__base_type] = STATE(16),
    [sym__literal] = STATE(55),
    [sym_type] = STATE(20),
    [sym_string] = STATE(55),
    [sym__statement] = STATE(100),
    [sym_access_control] = STATE(58),
    [sym_while_statement] = STATE(54),
    [sym_if_statement] = STATE(54),
    [sym_expression_statement] = STATE(54),
    [sym_variable_definition] = STATE(54),
    [sym__value] = STATE(55),
    [sym_collection] = STATE(60),
    [sym__number] = STATE(55),
    [sym_section_statement] = STATE(54),
    [sym_single_line_if_statement] = STATE(100),
    [sym__variable_statement] = STATE(54),
    [sym_assignment_expression] = STATE(59),
    [sym__collection_or_value] = STATE(60),
    [sym_character] = STATE(55),
    [anon_sym_i8] = ACTIONS(308),
    [anon_sym_return] = ACTIONS(311),
    [sym_float] = ACTIONS(314),
    [anon_sym_s32] = ACTIONS(308),
    [sym_binary] = ACTIONS(314),
    [anon_sym_while] = ACTIONS(317),
    [sym_null] = ACTIONS(320),
    [anon_sym_DQUOTE] = ACTIONS(323),
    [sym_readonly] = ACTIONS(326),
    [anon_sym_protected] = ACTIONS(329),
    [anon_sym_u16] = ACTIONS(308),
    [anon_sym_s8] = ACTIONS(308),
    [sym_double] = ACTIONS(320),
    [anon_sym_i16] = ACTIONS(308),
    [anon_sym_goto] = ACTIONS(332),
    [anon_sym_LBRACE] = ACTIONS(335),
    [anon_sym_private] = ACTIONS(329),
    [sym__comment] = ACTIONS(3),
    [anon_sym_publish] = ACTIONS(329),
    [anon_sym_u32] = ACTIONS(308),
    [anon_sym_s16] = ACTIONS(308),
    [anon_sym_f32] = ACTIONS(308),
    [anon_sym_LPAREN] = ACTIONS(338),
    [anon_sym_i32] = ACTIONS(308),
    [sym_oct] = ACTIONS(320),
    [sym_long] = ACTIONS(314),
    [sym_hex] = ACTIONS(314),
    [anon_sym_section] = ACTIONS(341),
    [anon_sym_if] = ACTIONS(344),
    [anon_sym_SQUOTE] = ACTIONS(347),
    [anon_sym_switch] = ACTIONS(350),
    [sym_identifier] = ACTIONS(353),
    [anon_sym_end] = ACTIONS(356),
    [anon_sym_u64] = ACTIONS(308),
    [anon_sym_u8] = ACTIONS(308),
    [anon_sym_f64] = ACTIONS(308),
    [sym_integer] = ACTIONS(320),
    [anon_sym_i64] = ACTIONS(308),
  },
  [101] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(358),
  },
  [102] = {
    [anon_sym_i8] = ACTIONS(360),
    [anon_sym_return] = ACTIONS(360),
    [sym_float] = ACTIONS(362),
    [anon_sym_s32] = ACTIONS(360),
    [sym_binary] = ACTIONS(362),
    [anon_sym_while] = ACTIONS(360),
    [sym_null] = ACTIONS(360),
    [anon_sym_DQUOTE] = ACTIONS(362),
    [sym_readonly] = ACTIONS(360),
    [anon_sym_protected] = ACTIONS(360),
    [anon_sym_u16] = ACTIONS(360),
    [anon_sym_s8] = ACTIONS(360),
    [sym_double] = ACTIONS(360),
    [anon_sym_i16] = ACTIONS(360),
    [anon_sym_goto] = ACTIONS(360),
    [anon_sym_LBRACE] = ACTIONS(362),
    [anon_sym_private] = ACTIONS(360),
    [sym__comment] = ACTIONS(3),
    [anon_sym_publish] = ACTIONS(360),
    [anon_sym_u32] = ACTIONS(360),
    [anon_sym_s16] = ACTIONS(360),
    [anon_sym_f32] = ACTIONS(360),
    [anon_sym_LPAREN] = ACTIONS(362),
    [anon_sym_i32] = ACTIONS(360),
    [sym_oct] = ACTIONS(360),
    [sym_long] = ACTIONS(362),
    [sym_hex] = ACTIONS(362),
    [anon_sym_section] = ACTIONS(360),
    [anon_sym_if] = ACTIONS(360),
    [anon_sym_SQUOTE] = ACTIONS(362),
    [anon_sym_switch] = ACTIONS(360),
    [sym_identifier] = ACTIONS(360),
    [anon_sym_end] = ACTIONS(360),
    [anon_sym_u64] = ACTIONS(360),
    [anon_sym_u8] = ACTIONS(360),
    [anon_sym_f64] = ACTIONS(360),
    [sym_integer] = ACTIONS(360),
    [anon_sym_i64] = ACTIONS(360),
  },
  [103] = {
    [anon_sym_RPAREN] = ACTIONS(364),
    [anon_sym_COMMA] = ACTIONS(364),
    [sym__comment] = ACTIONS(3),
    [anon_sym_RBRACE] = ACTIONS(364),
    [anon_sym_DOT] = ACTIONS(364),
  },
  [104] = {
    [anon_sym_RPAREN] = ACTIONS(366),
    [anon_sym_COMMA] = ACTIONS(366),
    [sym__comment] = ACTIONS(3),
    [anon_sym_RBRACE] = ACTIONS(366),
    [anon_sym_DOT] = ACTIONS(366),
  },
  [105] = {
    [anon_sym_i8] = ACTIONS(368),
    [anon_sym_method] = ACTIONS(368),
    [anon_sym_private] = ACTIONS(368),
    [anon_sym_s32] = ACTIONS(368),
    [anon_sym_publish] = ACTIONS(368),
    [anon_sym_u32] = ACTIONS(368),
    [anon_sym_s16] = ACTIONS(368),
    [anon_sym_f32] = ACTIONS(368),
    [sym_is_external] = ACTIONS(368),
    [anon_sym_i32] = ACTIONS(368),
    [sym__comment] = ACTIONS(3),
    [anon_sym_function] = ACTIONS(368),
    [sym_readonly] = ACTIONS(368),
    [anon_sym_protected] = ACTIONS(368),
    [anon_sym_u16] = ACTIONS(368),
    [anon_sym_s8] = ACTIONS(368),
    [sym_is_declare] = ACTIONS(368),
    [anon_sym_enum] = ACTIONS(368),
    [anon_sym_i16] = ACTIONS(368),
    [sym_identifier] = ACTIONS(368),
    [anon_sym_end] = ACTIONS(368),
    [anon_sym_u64] = ACTIONS(368),
    [anon_sym_u8] = ACTIONS(368),
    [anon_sym_f64] = ACTIONS(368),
    [anon_sym_i64] = ACTIONS(368),
  },
  [106] = {
    [anon_sym_LBRACE] = ACTIONS(370),
    [sym_double] = ACTIONS(372),
    [sym_binary] = ACTIONS(370),
    [sym__comment] = ACTIONS(3),
    [sym_oct] = ACTIONS(372),
    [anon_sym_SQUOTE] = ACTIONS(370),
    [sym_identifier] = ACTIONS(372),
    [anon_sym_LPAREN] = ACTIONS(370),
    [sym_long] = ACTIONS(370),
    [sym_null] = ACTIONS(372),
    [sym_integer] = ACTIONS(372),
    [anon_sym_DQUOTE] = ACTIONS(370),
    [sym_float] = ACTIONS(370),
    [sym_hex] = ACTIONS(370),
  },
  [107] = {
    [sym_collection] = STATE(147),
    [sym__value] = STATE(147),
    [sym__number] = STATE(147),
    [sym_group_expression] = STATE(147),
    [sym__literal] = STATE(147),
    [sym_string] = STATE(147),
    [sym__collection_or_value] = STATE(147),
    [sym_character] = STATE(147),
    [anon_sym_LBRACE] = ACTIONS(80),
    [sym_double] = ACTIONS(374),
    [sym_binary] = ACTIONS(376),
    [sym__comment] = ACTIONS(3),
    [sym_oct] = ACTIONS(374),
    [anon_sym_SQUOTE] = ACTIONS(88),
    [sym_identifier] = ACTIONS(374),
    [anon_sym_LPAREN] = ACTIONS(82),
    [sym_long] = ACTIONS(376),
    [sym_null] = ACTIONS(374),
    [sym_integer] = ACTIONS(374),
    [anon_sym_DQUOTE] = ACTIONS(74),
    [sym_float] = ACTIONS(376),
    [sym_hex] = ACTIONS(376),
  },
  [108] = {
    [anon_sym_i8] = ACTIONS(240),
    [anon_sym_method] = ACTIONS(240),
    [anon_sym_private] = ACTIONS(240),
    [anon_sym_s32] = ACTIONS(240),
    [anon_sym_publish] = ACTIONS(240),
    [anon_sym_u32] = ACTIONS(240),
    [anon_sym_s16] = ACTIONS(240),
    [anon_sym_f32] = ACTIONS(240),
    [sym_is_external] = ACTIONS(240),
    [anon_sym_i32] = ACTIONS(240),
    [sym__comment] = ACTIONS(3),
    [anon_sym_function] = ACTIONS(240),
    [sym_readonly] = ACTIONS(240),
    [anon_sym_protected] = ACTIONS(240),
    [anon_sym_u16] = ACTIONS(240),
    [anon_sym_s8] = ACTIONS(240),
    [sym_is_declare] = ACTIONS(240),
    [anon_sym_enum] = ACTIONS(240),
    [anon_sym_i16] = ACTIONS(240),
    [sym_identifier] = ACTIONS(240),
    [anon_sym_end] = ACTIONS(240),
    [anon_sym_u64] = ACTIONS(240),
    [anon_sym_u8] = ACTIONS(240),
    [anon_sym_f64] = ACTIONS(240),
    [anon_sym_i64] = ACTIONS(240),
  },
  [109] = {
    [sym_return_list] = STATE(149),
    [anon_sym_returns] = ACTIONS(146),
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(378),
  },
  [110] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(378),
  },
  [111] = {
    [sym_parameter_list] = STATE(150),
    [sym_return_list] = STATE(149),
    [anon_sym_LPAREN] = ACTIONS(144),
    [anon_sym_returns] = ACTIONS(146),
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(378),
  },
  [112] = {
    [anon_sym_i8] = ACTIONS(380),
    [anon_sym_method] = ACTIONS(380),
    [anon_sym_private] = ACTIONS(380),
    [anon_sym_s32] = ACTIONS(380),
    [anon_sym_publish] = ACTIONS(380),
    [anon_sym_u32] = ACTIONS(380),
    [anon_sym_s16] = ACTIONS(380),
    [anon_sym_f32] = ACTIONS(380),
    [sym_is_external] = ACTIONS(380),
    [anon_sym_i32] = ACTIONS(380),
    [sym__comment] = ACTIONS(3),
    [anon_sym_function] = ACTIONS(380),
    [sym_readonly] = ACTIONS(380),
    [anon_sym_protected] = ACTIONS(380),
    [anon_sym_u16] = ACTIONS(380),
    [anon_sym_s8] = ACTIONS(380),
    [sym_is_declare] = ACTIONS(380),
    [anon_sym_enum] = ACTIONS(380),
    [anon_sym_i16] = ACTIONS(380),
    [anon_sym_DOT] = ACTIONS(382),
    [sym_identifier] = ACTIONS(380),
    [anon_sym_COMMA] = ACTIONS(382),
    [anon_sym_end] = ACTIONS(380),
    [anon_sym_u64] = ACTIONS(380),
    [anon_sym_u8] = ACTIONS(380),
    [anon_sym_f64] = ACTIONS(380),
    [anon_sym_RPAREN] = ACTIONS(382),
    [anon_sym_i64] = ACTIONS(380),
  },
  [113] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(384),
    [anon_sym_RPAREN] = ACTIONS(384),
  },
  [114] = {
    [sym__enum_element] = STATE(151),
    [sym_identifier] = ACTIONS(102),
    [sym__comment] = ACTIONS(3),
  },
  [115] = {
    [sym_identifier] = ACTIONS(386),
    [sym__comment] = ACTIONS(3),
  },
  [116] = {
    [aux_sym_enum_definition_repeat1] = STATE(154),
    [sym__comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(218),
    [anon_sym_RPAREN] = ACTIONS(388),
  },
  [117] = {
    [sym_identifier] = ACTIONS(390),
    [anon_sym_COMMA] = ACTIONS(390),
    [sym__comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(390),
    [anon_sym_DOT] = ACTIONS(390),
  },
  [118] = {
    [anon_sym_returns] = ACTIONS(392),
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(392),
  },
  [119] = {
    [aux_sym__comma_list_variables_repeat1] = STATE(156),
    [sym__comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(394),
    [anon_sym_RPAREN] = ACTIONS(396),
  },
  [120] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_RPAREN] = ACTIONS(398),
  },
  [121] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(400),
  },
  [122] = {
    [aux_sym__comma_list_types_repeat1] = STATE(159),
    [sym__comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(402),
    [anon_sym_DOT] = ACTIONS(404),
  },
  [123] = {
    [aux_sym_type_repeat2] = STATE(160),
    [aux_sym_type_repeat1] = STATE(161),
    [sym_pointer] = STATE(161),
    [sym_array] = STATE(160),
    [anon_sym_COMMA] = ACTIONS(52),
    [anon_sym_STAR] = ACTIONS(54),
    [sym__comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(56),
    [anon_sym_DOT] = ACTIONS(52),
  },
  [124] = {
    [anon_sym_i8] = ACTIONS(406),
    [anon_sym_return] = ACTIONS(406),
    [sym_float] = ACTIONS(408),
    [anon_sym_s32] = ACTIONS(406),
    [sym_binary] = ACTIONS(408),
    [anon_sym_while] = ACTIONS(406),
    [sym_null] = ACTIONS(406),
    [anon_sym_DQUOTE] = ACTIONS(408),
    [sym_readonly] = ACTIONS(406),
    [anon_sym_protected] = ACTIONS(406),
    [anon_sym_u16] = ACTIONS(406),
    [anon_sym_s8] = ACTIONS(406),
    [sym_double] = ACTIONS(406),
    [anon_sym_i16] = ACTIONS(406),
    [anon_sym_goto] = ACTIONS(406),
    [anon_sym_LBRACE] = ACTIONS(408),
    [anon_sym_private] = ACTIONS(406),
    [sym__comment] = ACTIONS(3),
    [anon_sym_publish] = ACTIONS(406),
    [anon_sym_u32] = ACTIONS(406),
    [anon_sym_s16] = ACTIONS(406),
    [anon_sym_f32] = ACTIONS(406),
    [anon_sym_LPAREN] = ACTIONS(408),
    [anon_sym_i32] = ACTIONS(406),
    [sym_oct] = ACTIONS(406),
    [sym_long] = ACTIONS(408),
    [sym_hex] = ACTIONS(408),
    [anon_sym_section] = ACTIONS(406),
    [anon_sym_if] = ACTIONS(406),
    [anon_sym_SQUOTE] = ACTIONS(408),
    [anon_sym_switch] = ACTIONS(406),
    [sym_identifier] = ACTIONS(406),
    [anon_sym_end] = ACTIONS(406),
    [anon_sym_u64] = ACTIONS(406),
    [anon_sym_u8] = ACTIONS(406),
    [anon_sym_f64] = ACTIONS(406),
    [sym_integer] = ACTIONS(406),
    [anon_sym_i64] = ACTIONS(406),
  },
  [125] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(410),
  },
  [126] = {
    [anon_sym_i8] = ACTIONS(412),
    [anon_sym_method] = ACTIONS(412),
    [anon_sym_private] = ACTIONS(412),
    [anon_sym_s32] = ACTIONS(412),
    [anon_sym_publish] = ACTIONS(412),
    [anon_sym_u32] = ACTIONS(412),
    [anon_sym_s16] = ACTIONS(412),
    [anon_sym_f32] = ACTIONS(412),
    [sym_is_external] = ACTIONS(412),
    [anon_sym_i32] = ACTIONS(412),
    [sym__comment] = ACTIONS(3),
    [anon_sym_function] = ACTIONS(412),
    [sym_readonly] = ACTIONS(412),
    [anon_sym_protected] = ACTIONS(412),
    [anon_sym_u16] = ACTIONS(412),
    [anon_sym_s8] = ACTIONS(412),
    [sym_is_declare] = ACTIONS(412),
    [anon_sym_enum] = ACTIONS(412),
    [anon_sym_i16] = ACTIONS(412),
    [anon_sym_DOT] = ACTIONS(414),
    [sym_identifier] = ACTIONS(412),
    [anon_sym_COMMA] = ACTIONS(414),
    [anon_sym_end] = ACTIONS(412),
    [anon_sym_u64] = ACTIONS(412),
    [anon_sym_u8] = ACTIONS(412),
    [anon_sym_f64] = ACTIONS(412),
    [anon_sym_RPAREN] = ACTIONS(414),
    [anon_sym_i64] = ACTIONS(412),
  },
  [127] = {
    [sym_static_assignment] = STATE(163),
    [anon_sym_i8] = ACTIONS(380),
    [anon_sym_s32] = ACTIONS(380),
    [sym_is_external] = ACTIONS(380),
    [anon_sym_function] = ACTIONS(380),
    [sym_readonly] = ACTIONS(380),
    [anon_sym_protected] = ACTIONS(380),
    [anon_sym_u16] = ACTIONS(380),
    [anon_sym_s8] = ACTIONS(380),
    [anon_sym_enum] = ACTIONS(380),
    [anon_sym_i16] = ACTIONS(380),
    [anon_sym_method] = ACTIONS(380),
    [anon_sym_private] = ACTIONS(380),
    [sym__comment] = ACTIONS(3),
    [anon_sym_publish] = ACTIONS(380),
    [anon_sym_u32] = ACTIONS(380),
    [anon_sym_s16] = ACTIONS(380),
    [anon_sym_f32] = ACTIONS(380),
    [anon_sym_i32] = ACTIONS(380),
    [anon_sym_COLON_EQ] = ACTIONS(152),
    [sym_is_declare] = ACTIONS(380),
    [anon_sym_DOT] = ACTIONS(382),
    [sym_identifier] = ACTIONS(380),
    [anon_sym_COMMA] = ACTIONS(382),
    [anon_sym_end] = ACTIONS(380),
    [anon_sym_u64] = ACTIONS(380),
    [anon_sym_u8] = ACTIONS(380),
    [anon_sym_f64] = ACTIONS(380),
    [anon_sym_RPAREN] = ACTIONS(382),
    [anon_sym_i64] = ACTIONS(380),
  },
  [128] = {
    [sym_return_list] = STATE(164),
    [anon_sym_returns] = ACTIONS(146),
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(410),
  },
  [129] = {
    [sym_primitive_type] = STATE(16),
    [sym__control_flow_statement] = STATE(54),
    [sym_goto_statement] = STATE(54),
    [sym_switch_statement] = STATE(54),
    [aux_sym_function_definition_repeat1] = STATE(166),
    [sym_return_statement] = STATE(54),
    [sym_group_expression] = STATE(57),
    [sym__base_type] = STATE(16),
    [sym__literal] = STATE(55),
    [sym_type] = STATE(20),
    [sym_string] = STATE(55),
    [sym__statement] = STATE(166),
    [sym_access_control] = STATE(58),
    [sym_while_statement] = STATE(54),
    [sym_if_statement] = STATE(54),
    [sym_expression_statement] = STATE(54),
    [sym_end_while] = STATE(167),
    [sym_variable_definition] = STATE(54),
    [sym__value] = STATE(55),
    [sym_collection] = STATE(60),
    [sym__number] = STATE(55),
    [sym_section_statement] = STATE(54),
    [sym_single_line_if_statement] = STATE(166),
    [sym__variable_statement] = STATE(54),
    [sym_assignment_expression] = STATE(59),
    [sym__collection_or_value] = STATE(60),
    [sym_character] = STATE(55),
    [anon_sym_i8] = ACTIONS(22),
    [anon_sym_return] = ACTIONS(66),
    [anon_sym_i64] = ACTIONS(22),
    [anon_sym_s32] = ACTIONS(22),
    [sym_binary] = ACTIONS(68),
    [anon_sym_while] = ACTIONS(70),
    [sym_null] = ACTIONS(72),
    [anon_sym_DQUOTE] = ACTIONS(74),
    [sym_readonly] = ACTIONS(32),
    [anon_sym_protected] = ACTIONS(76),
    [anon_sym_u16] = ACTIONS(22),
    [anon_sym_s8] = ACTIONS(22),
    [sym_double] = ACTIONS(72),
    [anon_sym_i16] = ACTIONS(22),
    [anon_sym_goto] = ACTIONS(78),
    [anon_sym_LBRACE] = ACTIONS(80),
    [anon_sym_private] = ACTIONS(76),
    [sym__comment] = ACTIONS(3),
    [anon_sym_publish] = ACTIONS(76),
    [anon_sym_u32] = ACTIONS(22),
    [anon_sym_s16] = ACTIONS(22),
    [anon_sym_f32] = ACTIONS(22),
    [anon_sym_LPAREN] = ACTIONS(82),
    [anon_sym_i32] = ACTIONS(22),
    [sym_oct] = ACTIONS(72),
    [sym_long] = ACTIONS(68),
    [sym_hex] = ACTIONS(68),
    [anon_sym_section] = ACTIONS(84),
    [anon_sym_if] = ACTIONS(86),
    [anon_sym_SQUOTE] = ACTIONS(88),
    [sym_identifier] = ACTIONS(90),
    [anon_sym_switch] = ACTIONS(92),
    [anon_sym_end] = ACTIONS(416),
    [anon_sym_u64] = ACTIONS(22),
    [anon_sym_u8] = ACTIONS(22),
    [sym_float] = ACTIONS(68),
    [anon_sym_f64] = ACTIONS(22),
    [sym_integer] = ACTIONS(72),
  },
  [130] = {
    [anon_sym_PLUS] = ACTIONS(418),
    [anon_sym_s32] = ACTIONS(418),
    [anon_sym_PIPE_PIPE] = ACTIONS(420),
    [anon_sym_LT_LT] = ACTIONS(418),
    [anon_sym_LT_EQ] = ACTIONS(420),
    [anon_sym_function] = ACTIONS(418),
    [sym_readonly] = ACTIONS(418),
    [anon_sym_PLUS_PLUS] = ACTIONS(420),
    [anon_sym_protected] = ACTIONS(418),
    [anon_sym_s8] = ACTIONS(418),
    [anon_sym_enum] = ACTIONS(418),
    [anon_sym_SLASH] = ACTIONS(418),
    [anon_sym_STAR] = ACTIONS(418),
    [anon_sym_GT_GT] = ACTIONS(418),
    [anon_sym_PLUS_EQ] = ACTIONS(420),
    [anon_sym_BANG_EQ] = ACTIONS(420),
    [anon_sym_method] = ACTIONS(418),
    [anon_sym_private] = ACTIONS(418),
    [anon_sym_SLASH_EQ] = ACTIONS(420),
    [anon_sym_publish] = ACTIONS(418),
    [anon_sym_s16] = ACTIONS(418),
    [anon_sym_COLON_EQ] = ACTIONS(420),
    [sym_is_declare] = ACTIONS(418),
    [anon_sym_DASH_EQ] = ACTIONS(420),
    [anon_sym_PERCENT] = ACTIONS(418),
    [anon_sym_PERCENT_EQ] = ACTIONS(420),
    [anon_sym_end] = ACTIONS(418),
    [anon_sym_u8] = ACTIONS(418),
    [anon_sym_RPAREN] = ACTIONS(420),
    [anon_sym_i8] = ACTIONS(418),
    [sym_is_external] = ACTIONS(418),
    [anon_sym_STAR_EQ] = ACTIONS(420),
    [anon_sym_PIPE] = ACTIONS(418),
    [anon_sym_DASH_DASH] = ACTIONS(418),
    [anon_sym_AMP_EQ] = ACTIONS(420),
    [anon_sym_CARET_EQ] = ACTIONS(420),
    [anon_sym_u16] = ACTIONS(418),
    [anon_sym_i16] = ACTIONS(418),
    [anon_sym_DASH] = ACTIONS(418),
    [anon_sym_EQ_EQ] = ACTIONS(420),
    [anon_sym_CARET] = ACTIONS(418),
    [anon_sym_LT] = ACTIONS(418),
    [anon_sym_PIPE_EQ] = ACTIONS(420),
    [sym__comment] = ACTIONS(3),
    [anon_sym_GT_GT_EQ] = ACTIONS(420),
    [anon_sym_u32] = ACTIONS(418),
    [anon_sym_f32] = ACTIONS(418),
    [anon_sym_i32] = ACTIONS(418),
    [anon_sym_AMP] = ACTIONS(418),
    [anon_sym_AMP_AMP] = ACTIONS(420),
    [anon_sym_GT] = ACTIONS(418),
    [anon_sym_GT_EQ] = ACTIONS(420),
    [anon_sym_RBRACE] = ACTIONS(420),
    [anon_sym_DOT] = ACTIONS(420),
    [sym_identifier] = ACTIONS(418),
    [anon_sym_COMMA] = ACTIONS(420),
    [anon_sym_LT_LT_EQ] = ACTIONS(420),
    [anon_sym_u64] = ACTIONS(418),
    [anon_sym_f64] = ACTIONS(418),
    [anon_sym_i64] = ACTIONS(418),
  },
  [131] = {
    [aux_sym_string_repeat1] = STATE(131),
    [sym__comment] = ACTIONS(158),
    [anon_sym_DQUOTE] = ACTIONS(422),
    [aux_sym_string_token1] = ACTIONS(424),
  },
  [132] = {
    [anon_sym_i8] = ACTIONS(427),
    [anon_sym_i64] = ACTIONS(427),
    [anon_sym_RPAREN] = ACTIONS(429),
    [anon_sym_s32] = ACTIONS(427),
    [sym_is_external] = ACTIONS(427),
    [anon_sym_STAR_EQ] = ACTIONS(429),
    [anon_sym_function] = ACTIONS(427),
    [anon_sym_AMP_EQ] = ACTIONS(429),
    [sym_readonly] = ACTIONS(427),
    [anon_sym_CARET_EQ] = ACTIONS(429),
    [anon_sym_protected] = ACTIONS(427),
    [anon_sym_u16] = ACTIONS(427),
    [anon_sym_s8] = ACTIONS(427),
    [anon_sym_enum] = ACTIONS(427),
    [anon_sym_i16] = ACTIONS(427),
    [anon_sym_PLUS_EQ] = ACTIONS(429),
    [anon_sym_method] = ACTIONS(427),
    [anon_sym_PIPE_EQ] = ACTIONS(429),
    [anon_sym_SLASH_EQ] = ACTIONS(429),
    [anon_sym_GT_GT_EQ] = ACTIONS(429),
    [sym__comment] = ACTIONS(3),
    [anon_sym_private] = ACTIONS(427),
    [anon_sym_publish] = ACTIONS(427),
    [anon_sym_u32] = ACTIONS(427),
    [anon_sym_s16] = ACTIONS(427),
    [anon_sym_f32] = ACTIONS(427),
    [anon_sym_COLON_EQ] = ACTIONS(429),
    [anon_sym_i32] = ACTIONS(427),
    [sym_is_declare] = ACTIONS(427),
    [anon_sym_DASH_EQ] = ACTIONS(429),
    [anon_sym_RBRACE] = ACTIONS(429),
    [anon_sym_DOT] = ACTIONS(429),
    [sym_identifier] = ACTIONS(427),
    [anon_sym_PERCENT_EQ] = ACTIONS(429),
    [anon_sym_LT_LT_EQ] = ACTIONS(429),
    [anon_sym_COMMA] = ACTIONS(429),
    [anon_sym_end] = ACTIONS(427),
    [anon_sym_u64] = ACTIONS(427),
    [anon_sym_u8] = ACTIONS(427),
    [anon_sym_f64] = ACTIONS(427),
  },
  [133] = {
    [sym_collection] = STATE(82),
    [sym__value] = STATE(55),
    [sym__number] = STATE(55),
    [sym_group_expression] = STATE(55),
    [sym__assignment_or_collection_or_value] = STATE(168),
    [sym__literal] = STATE(55),
    [sym_string] = STATE(55),
    [sym_assignment_expression] = STATE(168),
    [sym__collection_or_value] = STATE(82),
    [sym_character] = STATE(55),
    [anon_sym_LBRACE] = ACTIONS(80),
    [sym_double] = ACTIONS(72),
    [sym_binary] = ACTIONS(68),
    [sym__comment] = ACTIONS(3),
    [sym_oct] = ACTIONS(72),
    [anon_sym_SQUOTE] = ACTIONS(88),
    [sym_identifier] = ACTIONS(72),
    [anon_sym_LPAREN] = ACTIONS(82),
    [sym_long] = ACTIONS(68),
    [sym_null] = ACTIONS(72),
    [sym_integer] = ACTIONS(72),
    [anon_sym_DQUOTE] = ACTIONS(74),
    [sym_float] = ACTIONS(68),
    [sym_hex] = ACTIONS(68),
  },
  [134] = {
    [aux_sym__comma_list_assignment_or_collection_or_value_repeat1] = STATE(169),
    [sym__comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(274),
    [anon_sym_RBRACE] = ACTIONS(431),
  },
  [135] = {
    [sym_double] = ACTIONS(433),
    [sym_binary] = ACTIONS(435),
    [sym__comment] = ACTIONS(3),
    [sym_oct] = ACTIONS(433),
    [anon_sym_SQUOTE] = ACTIONS(435),
    [sym_identifier] = ACTIONS(433),
    [anon_sym_LPAREN] = ACTIONS(435),
    [sym_long] = ACTIONS(435),
    [sym_null] = ACTIONS(433),
    [sym_integer] = ACTIONS(433),
    [anon_sym_DQUOTE] = ACTIONS(435),
    [sym_float] = ACTIONS(435),
    [sym_hex] = ACTIONS(435),
  },
  [136] = {
    [anon_sym_PLUS] = ACTIONS(437),
    [anon_sym_s32] = ACTIONS(437),
    [anon_sym_PIPE_PIPE] = ACTIONS(439),
    [anon_sym_LT_LT] = ACTIONS(437),
    [anon_sym_LT_EQ] = ACTIONS(439),
    [anon_sym_function] = ACTIONS(437),
    [sym_readonly] = ACTIONS(437),
    [anon_sym_PLUS_PLUS] = ACTIONS(439),
    [anon_sym_protected] = ACTIONS(437),
    [anon_sym_s8] = ACTIONS(437),
    [anon_sym_enum] = ACTIONS(437),
    [anon_sym_SLASH] = ACTIONS(437),
    [anon_sym_STAR] = ACTIONS(437),
    [anon_sym_GT_GT] = ACTIONS(437),
    [anon_sym_PLUS_EQ] = ACTIONS(439),
    [anon_sym_BANG_EQ] = ACTIONS(439),
    [anon_sym_method] = ACTIONS(437),
    [anon_sym_private] = ACTIONS(437),
    [anon_sym_SLASH_EQ] = ACTIONS(439),
    [anon_sym_publish] = ACTIONS(437),
    [anon_sym_s16] = ACTIONS(437),
    [anon_sym_COLON_EQ] = ACTIONS(439),
    [sym_is_declare] = ACTIONS(437),
    [anon_sym_DASH_EQ] = ACTIONS(439),
    [anon_sym_PERCENT] = ACTIONS(437),
    [anon_sym_PERCENT_EQ] = ACTIONS(439),
    [anon_sym_end] = ACTIONS(437),
    [anon_sym_u8] = ACTIONS(437),
    [anon_sym_RPAREN] = ACTIONS(439),
    [anon_sym_i8] = ACTIONS(437),
    [sym_is_external] = ACTIONS(437),
    [anon_sym_STAR_EQ] = ACTIONS(439),
    [anon_sym_PIPE] = ACTIONS(437),
    [anon_sym_DASH_DASH] = ACTIONS(437),
    [anon_sym_AMP_EQ] = ACTIONS(439),
    [anon_sym_CARET_EQ] = ACTIONS(439),
    [anon_sym_u16] = ACTIONS(437),
    [anon_sym_i16] = ACTIONS(437),
    [anon_sym_DASH] = ACTIONS(437),
    [anon_sym_EQ_EQ] = ACTIONS(439),
    [anon_sym_CARET] = ACTIONS(437),
    [anon_sym_LT] = ACTIONS(437),
    [anon_sym_PIPE_EQ] = ACTIONS(439),
    [sym__comment] = ACTIONS(3),
    [anon_sym_GT_GT_EQ] = ACTIONS(439),
    [anon_sym_u32] = ACTIONS(437),
    [anon_sym_f32] = ACTIONS(437),
    [anon_sym_i32] = ACTIONS(437),
    [anon_sym_AMP] = ACTIONS(437),
    [anon_sym_AMP_AMP] = ACTIONS(439),
    [anon_sym_GT] = ACTIONS(437),
    [anon_sym_GT_EQ] = ACTIONS(439),
    [anon_sym_RBRACE] = ACTIONS(439),
    [anon_sym_DOT] = ACTIONS(439),
    [sym_identifier] = ACTIONS(437),
    [anon_sym_COMMA] = ACTIONS(439),
    [anon_sym_LT_LT_EQ] = ACTIONS(439),
    [anon_sym_u64] = ACTIONS(437),
    [anon_sym_f64] = ACTIONS(437),
    [anon_sym_i64] = ACTIONS(437),
  },
  [137] = {
    [sym__literal] = STATE(170),
    [sym_string] = STATE(170),
    [sym__value] = STATE(170),
    [sym__number] = STATE(170),
    [sym_group_expression] = STATE(170),
    [sym_character] = STATE(170),
    [sym_double] = ACTIONS(441),
    [sym_binary] = ACTIONS(443),
    [sym__comment] = ACTIONS(3),
    [sym_oct] = ACTIONS(441),
    [anon_sym_SQUOTE] = ACTIONS(88),
    [sym_identifier] = ACTIONS(441),
    [anon_sym_LPAREN] = ACTIONS(82),
    [sym_long] = ACTIONS(443),
    [sym_null] = ACTIONS(441),
    [sym_integer] = ACTIONS(441),
    [anon_sym_DQUOTE] = ACTIONS(74),
    [sym_float] = ACTIONS(443),
    [sym_hex] = ACTIONS(443),
  },
  [138] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_RPAREN] = ACTIONS(445),
  },
  [139] = {
    [sym_binary_op] = STATE(173),
    [sym_assignment_post_op] = STATE(104),
    [anon_sym_PLUS] = ACTIONS(282),
    [anon_sym_PIPE_PIPE] = ACTIONS(284),
    [anon_sym_STAR_EQ] = ACTIONS(196),
    [anon_sym_LT_LT] = ACTIONS(282),
    [anon_sym_PIPE] = ACTIONS(282),
    [anon_sym_LT_EQ] = ACTIONS(284),
    [anon_sym_DASH_DASH] = ACTIONS(198),
    [anon_sym_AMP_EQ] = ACTIONS(196),
    [anon_sym_PLUS_PLUS] = ACTIONS(200),
    [anon_sym_CARET_EQ] = ACTIONS(196),
    [anon_sym_DASH] = ACTIONS(282),
    [anon_sym_SLASH] = ACTIONS(282),
    [anon_sym_STAR] = ACTIONS(282),
    [anon_sym_GT_GT] = ACTIONS(282),
    [anon_sym_EQ_EQ] = ACTIONS(284),
    [anon_sym_PLUS_EQ] = ACTIONS(196),
    [anon_sym_CARET] = ACTIONS(282),
    [anon_sym_BANG_EQ] = ACTIONS(284),
    [anon_sym_LT] = ACTIONS(282),
    [anon_sym_PIPE_EQ] = ACTIONS(196),
    [anon_sym_SLASH_EQ] = ACTIONS(196),
    [anon_sym_GT_GT_EQ] = ACTIONS(196),
    [sym__comment] = ACTIONS(3),
    [anon_sym_AMP] = ACTIONS(282),
    [anon_sym_COLON_EQ] = ACTIONS(196),
    [anon_sym_AMP_AMP] = ACTIONS(284),
    [anon_sym_DASH_EQ] = ACTIONS(196),
    [anon_sym_GT] = ACTIONS(282),
    [anon_sym_PERCENT] = ACTIONS(282),
    [anon_sym_GT_EQ] = ACTIONS(284),
    [anon_sym_PERCENT_EQ] = ACTIONS(196),
    [anon_sym_LT_LT_EQ] = ACTIONS(196),
    [anon_sym_RPAREN] = ACTIONS(447),
  },
  [140] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_RPAREN] = ACTIONS(447),
  },
  [141] = {
    [sym__literal] = STATE(174),
    [sym_string] = STATE(174),
    [sym__value] = STATE(174),
    [sym__number] = STATE(174),
    [sym_group_expression] = STATE(174),
    [sym_character] = STATE(174),
    [sym_double] = ACTIONS(449),
    [sym_binary] = ACTIONS(451),
    [sym__comment] = ACTIONS(3),
    [sym_oct] = ACTIONS(449),
    [anon_sym_SQUOTE] = ACTIONS(88),
    [sym_identifier] = ACTIONS(449),
    [anon_sym_LPAREN] = ACTIONS(82),
    [sym_long] = ACTIONS(451),
    [sym_null] = ACTIONS(449),
    [sym_integer] = ACTIONS(449),
    [anon_sym_DQUOTE] = ACTIONS(74),
    [sym_float] = ACTIONS(451),
    [sym_hex] = ACTIONS(451),
  },
  [142] = {
    [sym_primitive_type] = STATE(16),
    [sym__control_flow_statement] = STATE(54),
    [sym_goto_statement] = STATE(54),
    [sym_switch_statement] = STATE(54),
    [aux_sym_function_definition_repeat1] = STATE(176),
    [sym_return_statement] = STATE(54),
    [sym_group_expression] = STATE(57),
    [sym__base_type] = STATE(16),
    [sym__literal] = STATE(55),
    [sym_type] = STATE(20),
    [sym_string] = STATE(55),
    [sym__statement] = STATE(176),
    [sym_access_control] = STATE(58),
    [sym_while_statement] = STATE(54),
    [sym_if_statement] = STATE(54),
    [sym_expression_statement] = STATE(54),
    [sym_variable_definition] = STATE(54),
    [sym__value] = STATE(55),
    [sym_collection] = STATE(60),
    [sym__number] = STATE(55),
    [sym_section_statement] = STATE(54),
    [sym_single_line_if_statement] = STATE(176),
    [sym__variable_statement] = STATE(54),
    [sym_assignment_expression] = STATE(59),
    [sym_end_if] = STATE(177),
    [sym__collection_or_value] = STATE(60),
    [sym_character] = STATE(55),
    [anon_sym_i8] = ACTIONS(22),
    [anon_sym_return] = ACTIONS(66),
    [anon_sym_i64] = ACTIONS(22),
    [anon_sym_s32] = ACTIONS(22),
    [sym_binary] = ACTIONS(68),
    [anon_sym_while] = ACTIONS(70),
    [sym_null] = ACTIONS(72),
    [anon_sym_DQUOTE] = ACTIONS(74),
    [sym_readonly] = ACTIONS(32),
    [anon_sym_protected] = ACTIONS(76),
    [anon_sym_u16] = ACTIONS(22),
    [anon_sym_s8] = ACTIONS(22),
    [sym_double] = ACTIONS(72),
    [anon_sym_i16] = ACTIONS(22),
    [anon_sym_goto] = ACTIONS(78),
    [anon_sym_LBRACE] = ACTIONS(80),
    [anon_sym_private] = ACTIONS(76),
    [sym__comment] = ACTIONS(3),
    [anon_sym_publish] = ACTIONS(76),
    [anon_sym_u32] = ACTIONS(22),
    [anon_sym_s16] = ACTIONS(22),
    [anon_sym_f32] = ACTIONS(22),
    [anon_sym_LPAREN] = ACTIONS(82),
    [anon_sym_i32] = ACTIONS(22),
    [sym_oct] = ACTIONS(72),
    [sym_long] = ACTIONS(68),
    [sym_hex] = ACTIONS(68),
    [anon_sym_section] = ACTIONS(84),
    [anon_sym_if] = ACTIONS(86),
    [anon_sym_SQUOTE] = ACTIONS(88),
    [sym_identifier] = ACTIONS(90),
    [anon_sym_switch] = ACTIONS(92),
    [anon_sym_end] = ACTIONS(453),
    [anon_sym_u64] = ACTIONS(22),
    [anon_sym_u8] = ACTIONS(22),
    [sym_float] = ACTIONS(68),
    [anon_sym_f64] = ACTIONS(22),
    [sym_integer] = ACTIONS(72),
  },
  [143] = {
    [anon_sym_i8] = ACTIONS(455),
    [anon_sym_return] = ACTIONS(455),
    [sym_float] = ACTIONS(457),
    [anon_sym_s32] = ACTIONS(455),
    [sym_binary] = ACTIONS(457),
    [anon_sym_while] = ACTIONS(455),
    [sym_null] = ACTIONS(455),
    [anon_sym_DQUOTE] = ACTIONS(457),
    [sym_readonly] = ACTIONS(455),
    [anon_sym_protected] = ACTIONS(455),
    [anon_sym_u16] = ACTIONS(455),
    [anon_sym_s8] = ACTIONS(455),
    [sym_double] = ACTIONS(455),
    [anon_sym_i16] = ACTIONS(455),
    [anon_sym_goto] = ACTIONS(455),
    [anon_sym_LBRACE] = ACTIONS(457),
    [anon_sym_private] = ACTIONS(455),
    [sym__comment] = ACTIONS(3),
    [anon_sym_publish] = ACTIONS(455),
    [anon_sym_u32] = ACTIONS(455),
    [anon_sym_s16] = ACTIONS(455),
    [anon_sym_f32] = ACTIONS(455),
    [anon_sym_LPAREN] = ACTIONS(457),
    [anon_sym_i32] = ACTIONS(455),
    [sym_oct] = ACTIONS(455),
    [sym_long] = ACTIONS(457),
    [sym_hex] = ACTIONS(457),
    [anon_sym_section] = ACTIONS(455),
    [anon_sym_if] = ACTIONS(455),
    [anon_sym_SQUOTE] = ACTIONS(457),
    [anon_sym_switch] = ACTIONS(455),
    [sym_identifier] = ACTIONS(455),
    [anon_sym_end] = ACTIONS(455),
    [anon_sym_u64] = ACTIONS(455),
    [anon_sym_u8] = ACTIONS(455),
    [anon_sym_f64] = ACTIONS(455),
    [sym_integer] = ACTIONS(455),
    [anon_sym_i64] = ACTIONS(455),
  },
  [144] = {
    [anon_sym_PLUS] = ACTIONS(459),
    [anon_sym_s32] = ACTIONS(459),
    [anon_sym_PIPE_PIPE] = ACTIONS(461),
    [anon_sym_LT_LT] = ACTIONS(459),
    [anon_sym_LT_EQ] = ACTIONS(461),
    [anon_sym_function] = ACTIONS(459),
    [sym_readonly] = ACTIONS(459),
    [anon_sym_PLUS_PLUS] = ACTIONS(461),
    [anon_sym_protected] = ACTIONS(459),
    [anon_sym_s8] = ACTIONS(459),
    [anon_sym_enum] = ACTIONS(459),
    [anon_sym_SLASH] = ACTIONS(459),
    [anon_sym_STAR] = ACTIONS(459),
    [anon_sym_GT_GT] = ACTIONS(459),
    [anon_sym_PLUS_EQ] = ACTIONS(461),
    [anon_sym_BANG_EQ] = ACTIONS(461),
    [anon_sym_method] = ACTIONS(459),
    [anon_sym_private] = ACTIONS(459),
    [anon_sym_SLASH_EQ] = ACTIONS(461),
    [anon_sym_publish] = ACTIONS(459),
    [anon_sym_s16] = ACTIONS(459),
    [anon_sym_COLON_EQ] = ACTIONS(461),
    [sym_is_declare] = ACTIONS(459),
    [anon_sym_DASH_EQ] = ACTIONS(461),
    [anon_sym_PERCENT] = ACTIONS(459),
    [anon_sym_PERCENT_EQ] = ACTIONS(461),
    [anon_sym_end] = ACTIONS(459),
    [anon_sym_u8] = ACTIONS(459),
    [anon_sym_RPAREN] = ACTIONS(461),
    [anon_sym_i8] = ACTIONS(459),
    [sym_is_external] = ACTIONS(459),
    [anon_sym_STAR_EQ] = ACTIONS(461),
    [anon_sym_PIPE] = ACTIONS(459),
    [anon_sym_DASH_DASH] = ACTIONS(459),
    [anon_sym_AMP_EQ] = ACTIONS(461),
    [anon_sym_CARET_EQ] = ACTIONS(461),
    [anon_sym_u16] = ACTIONS(459),
    [anon_sym_i16] = ACTIONS(459),
    [anon_sym_DASH] = ACTIONS(459),
    [anon_sym_EQ_EQ] = ACTIONS(461),
    [anon_sym_CARET] = ACTIONS(459),
    [anon_sym_LT] = ACTIONS(459),
    [anon_sym_PIPE_EQ] = ACTIONS(461),
    [sym__comment] = ACTIONS(3),
    [anon_sym_GT_GT_EQ] = ACTIONS(461),
    [anon_sym_u32] = ACTIONS(459),
    [anon_sym_f32] = ACTIONS(459),
    [anon_sym_i32] = ACTIONS(459),
    [anon_sym_AMP] = ACTIONS(459),
    [anon_sym_AMP_AMP] = ACTIONS(461),
    [anon_sym_GT] = ACTIONS(459),
    [anon_sym_GT_EQ] = ACTIONS(461),
    [anon_sym_RBRACE] = ACTIONS(461),
    [anon_sym_DOT] = ACTIONS(461),
    [sym_identifier] = ACTIONS(459),
    [anon_sym_COMMA] = ACTIONS(461),
    [anon_sym_LT_LT_EQ] = ACTIONS(461),
    [anon_sym_u64] = ACTIONS(459),
    [anon_sym_f64] = ACTIONS(459),
    [anon_sym_i64] = ACTIONS(459),
  },
  [145] = {
    [sym_case_statement] = STATE(181),
    [sym_default_statement] = STATE(180),
    [aux_sym_switch_statement_repeat1] = STATE(181),
    [sym__comment] = ACTIONS(3),
    [anon_sym_case] = ACTIONS(463),
    [anon_sym_default] = ACTIONS(465),
  },
  [146] = {
    [anon_sym_i8] = ACTIONS(467),
    [anon_sym_method] = ACTIONS(467),
    [anon_sym_private] = ACTIONS(467),
    [anon_sym_s32] = ACTIONS(467),
    [anon_sym_publish] = ACTIONS(467),
    [anon_sym_u32] = ACTIONS(467),
    [anon_sym_s16] = ACTIONS(467),
    [anon_sym_f32] = ACTIONS(467),
    [sym_is_external] = ACTIONS(467),
    [anon_sym_i32] = ACTIONS(467),
    [sym__comment] = ACTIONS(3),
    [anon_sym_function] = ACTIONS(467),
    [sym_readonly] = ACTIONS(467),
    [anon_sym_protected] = ACTIONS(467),
    [anon_sym_u16] = ACTIONS(467),
    [anon_sym_s8] = ACTIONS(467),
    [sym_is_declare] = ACTIONS(467),
    [anon_sym_enum] = ACTIONS(467),
    [anon_sym_i16] = ACTIONS(467),
    [sym_identifier] = ACTIONS(467),
    [anon_sym_end] = ACTIONS(467),
    [anon_sym_u64] = ACTIONS(467),
    [anon_sym_u8] = ACTIONS(467),
    [anon_sym_f64] = ACTIONS(467),
    [anon_sym_i64] = ACTIONS(467),
  },
  [147] = {
    [anon_sym_RPAREN] = ACTIONS(469),
    [anon_sym_COMMA] = ACTIONS(469),
    [sym__comment] = ACTIONS(3),
    [anon_sym_RBRACE] = ACTIONS(469),
    [anon_sym_DOT] = ACTIONS(469),
  },
  [148] = {
    [anon_sym_i8] = ACTIONS(406),
    [anon_sym_method] = ACTIONS(406),
    [anon_sym_private] = ACTIONS(406),
    [anon_sym_s32] = ACTIONS(406),
    [anon_sym_publish] = ACTIONS(406),
    [anon_sym_u32] = ACTIONS(406),
    [anon_sym_s16] = ACTIONS(406),
    [anon_sym_f32] = ACTIONS(406),
    [sym_is_external] = ACTIONS(406),
    [anon_sym_i32] = ACTIONS(406),
    [sym__comment] = ACTIONS(3),
    [anon_sym_function] = ACTIONS(406),
    [sym_readonly] = ACTIONS(406),
    [anon_sym_protected] = ACTIONS(406),
    [anon_sym_u16] = ACTIONS(406),
    [anon_sym_s8] = ACTIONS(406),
    [sym_is_declare] = ACTIONS(406),
    [anon_sym_enum] = ACTIONS(406),
    [anon_sym_i16] = ACTIONS(406),
    [sym_identifier] = ACTIONS(406),
    [anon_sym_end] = ACTIONS(406),
    [anon_sym_u64] = ACTIONS(406),
    [anon_sym_u8] = ACTIONS(406),
    [anon_sym_f64] = ACTIONS(406),
    [anon_sym_i64] = ACTIONS(406),
  },
  [149] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(471),
  },
  [150] = {
    [sym_return_list] = STATE(183),
    [anon_sym_returns] = ACTIONS(146),
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(471),
  },
  [151] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(473),
    [anon_sym_RPAREN] = ACTIONS(473),
  },
  [152] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(475),
  },
  [153] = {
    [sym_identifier] = ACTIONS(477),
    [sym__comment] = ACTIONS(3),
  },
  [154] = {
    [aux_sym_enum_definition_repeat1] = STATE(154),
    [sym__comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(479),
    [anon_sym_RPAREN] = ACTIONS(473),
  },
  [155] = {
    [sym_primitive_type] = STATE(16),
    [sym_type] = STATE(20),
    [sym_variable_definition] = STATE(186),
    [sym_access_control] = STATE(58),
    [sym__base_type] = STATE(16),
    [anon_sym_i8] = ACTIONS(22),
    [anon_sym_private] = ACTIONS(76),
    [anon_sym_s32] = ACTIONS(22),
    [anon_sym_publish] = ACTIONS(76),
    [anon_sym_u32] = ACTIONS(22),
    [anon_sym_s16] = ACTIONS(22),
    [anon_sym_f32] = ACTIONS(22),
    [sym__comment] = ACTIONS(3),
    [anon_sym_i32] = ACTIONS(22),
    [sym_readonly] = ACTIONS(32),
    [anon_sym_protected] = ACTIONS(76),
    [anon_sym_u16] = ACTIONS(22),
    [anon_sym_s8] = ACTIONS(22),
    [anon_sym_i16] = ACTIONS(22),
    [sym_identifier] = ACTIONS(36),
    [anon_sym_u64] = ACTIONS(22),
    [anon_sym_u8] = ACTIONS(22),
    [anon_sym_f64] = ACTIONS(22),
    [anon_sym_i64] = ACTIONS(22),
  },
  [156] = {
    [aux_sym__comma_list_variables_repeat1] = STATE(187),
    [sym__comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(394),
    [anon_sym_RPAREN] = ACTIONS(482),
  },
  [157] = {
    [anon_sym_returns] = ACTIONS(484),
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(484),
  },
  [158] = {
    [sym_primitive_type] = STATE(123),
    [sym_type] = STATE(188),
    [sym__base_type] = STATE(123),
    [anon_sym_i8] = ACTIONS(22),
    [anon_sym_s32] = ACTIONS(22),
    [sym__comment] = ACTIONS(3),
    [anon_sym_u32] = ACTIONS(22),
    [anon_sym_s16] = ACTIONS(22),
    [anon_sym_f32] = ACTIONS(22),
    [anon_sym_i32] = ACTIONS(22),
    [anon_sym_u16] = ACTIONS(22),
    [anon_sym_s8] = ACTIONS(22),
    [anon_sym_i16] = ACTIONS(22),
    [sym_identifier] = ACTIONS(246),
    [anon_sym_u64] = ACTIONS(22),
    [anon_sym_u8] = ACTIONS(22),
    [anon_sym_f64] = ACTIONS(22),
    [anon_sym_i64] = ACTIONS(22),
  },
  [159] = {
    [aux_sym__comma_list_types_repeat1] = STATE(189),
    [sym__comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(402),
    [anon_sym_DOT] = ACTIONS(486),
  },
  [160] = {
    [aux_sym_type_repeat2] = STATE(190),
    [sym_array] = STATE(190),
    [anon_sym_COMMA] = ACTIONS(112),
    [sym__comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(56),
    [anon_sym_DOT] = ACTIONS(112),
  },
  [161] = {
    [aux_sym_type_repeat2] = STATE(191),
    [aux_sym_type_repeat1] = STATE(192),
    [sym_pointer] = STATE(192),
    [sym_array] = STATE(191),
    [anon_sym_COMMA] = ACTIONS(112),
    [anon_sym_STAR] = ACTIONS(54),
    [sym__comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(56),
    [anon_sym_DOT] = ACTIONS(112),
  },
  [162] = {
    [anon_sym_i8] = ACTIONS(488),
    [anon_sym_return] = ACTIONS(488),
    [sym_float] = ACTIONS(490),
    [anon_sym_s32] = ACTIONS(488),
    [sym_binary] = ACTIONS(490),
    [anon_sym_while] = ACTIONS(488),
    [sym_null] = ACTIONS(488),
    [anon_sym_DQUOTE] = ACTIONS(490),
    [sym_readonly] = ACTIONS(488),
    [anon_sym_protected] = ACTIONS(488),
    [anon_sym_u16] = ACTIONS(488),
    [anon_sym_s8] = ACTIONS(488),
    [sym_double] = ACTIONS(488),
    [anon_sym_i16] = ACTIONS(488),
    [anon_sym_goto] = ACTIONS(488),
    [anon_sym_LBRACE] = ACTIONS(490),
    [anon_sym_private] = ACTIONS(488),
    [sym__comment] = ACTIONS(3),
    [anon_sym_publish] = ACTIONS(488),
    [anon_sym_u32] = ACTIONS(488),
    [anon_sym_s16] = ACTIONS(488),
    [anon_sym_f32] = ACTIONS(488),
    [anon_sym_LPAREN] = ACTIONS(490),
    [anon_sym_i32] = ACTIONS(488),
    [sym_oct] = ACTIONS(488),
    [sym_long] = ACTIONS(490),
    [sym_hex] = ACTIONS(490),
    [anon_sym_section] = ACTIONS(488),
    [anon_sym_if] = ACTIONS(488),
    [anon_sym_SQUOTE] = ACTIONS(490),
    [anon_sym_switch] = ACTIONS(488),
    [sym_identifier] = ACTIONS(488),
    [anon_sym_end] = ACTIONS(488),
    [anon_sym_u64] = ACTIONS(488),
    [anon_sym_u8] = ACTIONS(488),
    [anon_sym_f64] = ACTIONS(488),
    [sym_integer] = ACTIONS(488),
    [anon_sym_i64] = ACTIONS(488),
  },
  [163] = {
    [anon_sym_i8] = ACTIONS(492),
    [anon_sym_method] = ACTIONS(492),
    [anon_sym_private] = ACTIONS(492),
    [anon_sym_s32] = ACTIONS(492),
    [anon_sym_publish] = ACTIONS(492),
    [anon_sym_u32] = ACTIONS(492),
    [anon_sym_s16] = ACTIONS(492),
    [anon_sym_f32] = ACTIONS(492),
    [sym_is_external] = ACTIONS(492),
    [anon_sym_i32] = ACTIONS(492),
    [sym__comment] = ACTIONS(3),
    [anon_sym_function] = ACTIONS(492),
    [sym_readonly] = ACTIONS(492),
    [anon_sym_protected] = ACTIONS(492),
    [anon_sym_u16] = ACTIONS(492),
    [anon_sym_s8] = ACTIONS(492),
    [sym_is_declare] = ACTIONS(492),
    [anon_sym_enum] = ACTIONS(492),
    [anon_sym_i16] = ACTIONS(492),
    [anon_sym_DOT] = ACTIONS(494),
    [sym_identifier] = ACTIONS(492),
    [anon_sym_COMMA] = ACTIONS(494),
    [anon_sym_end] = ACTIONS(492),
    [anon_sym_u64] = ACTIONS(492),
    [anon_sym_u8] = ACTIONS(492),
    [anon_sym_f64] = ACTIONS(492),
    [anon_sym_RPAREN] = ACTIONS(494),
    [anon_sym_i64] = ACTIONS(492),
  },
  [164] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(496),
  },
  [165] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_while] = ACTIONS(498),
  },
  [166] = {
    [sym_primitive_type] = STATE(16),
    [sym__control_flow_statement] = STATE(54),
    [sym_goto_statement] = STATE(54),
    [sym_switch_statement] = STATE(54),
    [aux_sym_function_definition_repeat1] = STATE(100),
    [sym_return_statement] = STATE(54),
    [sym_group_expression] = STATE(57),
    [sym__base_type] = STATE(16),
    [sym__literal] = STATE(55),
    [sym_type] = STATE(20),
    [sym_string] = STATE(55),
    [sym__statement] = STATE(100),
    [sym_access_control] = STATE(58),
    [sym_while_statement] = STATE(54),
    [sym_if_statement] = STATE(54),
    [sym_expression_statement] = STATE(54),
    [sym_end_while] = STATE(195),
    [sym_variable_definition] = STATE(54),
    [sym__value] = STATE(55),
    [sym_collection] = STATE(60),
    [sym__number] = STATE(55),
    [sym_section_statement] = STATE(54),
    [sym_single_line_if_statement] = STATE(100),
    [sym__variable_statement] = STATE(54),
    [sym_assignment_expression] = STATE(59),
    [sym__collection_or_value] = STATE(60),
    [sym_character] = STATE(55),
    [anon_sym_i8] = ACTIONS(22),
    [anon_sym_return] = ACTIONS(66),
    [anon_sym_i64] = ACTIONS(22),
    [anon_sym_s32] = ACTIONS(22),
    [sym_binary] = ACTIONS(68),
    [anon_sym_while] = ACTIONS(70),
    [sym_null] = ACTIONS(72),
    [anon_sym_DQUOTE] = ACTIONS(74),
    [sym_readonly] = ACTIONS(32),
    [anon_sym_protected] = ACTIONS(76),
    [anon_sym_u16] = ACTIONS(22),
    [anon_sym_s8] = ACTIONS(22),
    [sym_double] = ACTIONS(72),
    [anon_sym_i16] = ACTIONS(22),
    [anon_sym_goto] = ACTIONS(78),
    [anon_sym_LBRACE] = ACTIONS(80),
    [anon_sym_private] = ACTIONS(76),
    [sym__comment] = ACTIONS(3),
    [anon_sym_publish] = ACTIONS(76),
    [anon_sym_u32] = ACTIONS(22),
    [anon_sym_s16] = ACTIONS(22),
    [anon_sym_f32] = ACTIONS(22),
    [anon_sym_LPAREN] = ACTIONS(82),
    [anon_sym_i32] = ACTIONS(22),
    [sym_oct] = ACTIONS(72),
    [sym_long] = ACTIONS(68),
    [sym_hex] = ACTIONS(68),
    [anon_sym_section] = ACTIONS(84),
    [anon_sym_if] = ACTIONS(86),
    [anon_sym_SQUOTE] = ACTIONS(88),
    [sym_identifier] = ACTIONS(90),
    [anon_sym_switch] = ACTIONS(92),
    [anon_sym_end] = ACTIONS(416),
    [anon_sym_u64] = ACTIONS(22),
    [anon_sym_u8] = ACTIONS(22),
    [sym_float] = ACTIONS(68),
    [anon_sym_f64] = ACTIONS(22),
    [sym_integer] = ACTIONS(72),
  },
  [167] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(500),
  },
  [168] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(502),
    [anon_sym_RBRACE] = ACTIONS(502),
  },
  [169] = {
    [aux_sym__comma_list_assignment_or_collection_or_value_repeat1] = STATE(169),
    [sym__comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(504),
    [anon_sym_RBRACE] = ACTIONS(502),
  },
  [170] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_RPAREN] = ACTIONS(507),
  },
  [171] = {
    [anon_sym_PLUS] = ACTIONS(509),
    [anon_sym_s32] = ACTIONS(509),
    [anon_sym_PIPE_PIPE] = ACTIONS(511),
    [anon_sym_LT_LT] = ACTIONS(509),
    [anon_sym_LT_EQ] = ACTIONS(511),
    [anon_sym_function] = ACTIONS(509),
    [sym_readonly] = ACTIONS(509),
    [anon_sym_PLUS_PLUS] = ACTIONS(511),
    [anon_sym_protected] = ACTIONS(509),
    [anon_sym_s8] = ACTIONS(509),
    [anon_sym_enum] = ACTIONS(509),
    [anon_sym_SLASH] = ACTIONS(509),
    [anon_sym_STAR] = ACTIONS(509),
    [anon_sym_GT_GT] = ACTIONS(509),
    [anon_sym_PLUS_EQ] = ACTIONS(511),
    [anon_sym_BANG_EQ] = ACTIONS(511),
    [anon_sym_method] = ACTIONS(509),
    [anon_sym_private] = ACTIONS(509),
    [anon_sym_SLASH_EQ] = ACTIONS(511),
    [anon_sym_publish] = ACTIONS(509),
    [anon_sym_s16] = ACTIONS(509),
    [anon_sym_COLON_EQ] = ACTIONS(511),
    [sym_is_declare] = ACTIONS(509),
    [anon_sym_DASH_EQ] = ACTIONS(511),
    [anon_sym_PERCENT] = ACTIONS(509),
    [anon_sym_PERCENT_EQ] = ACTIONS(511),
    [anon_sym_end] = ACTIONS(509),
    [anon_sym_u8] = ACTIONS(509),
    [anon_sym_RPAREN] = ACTIONS(511),
    [anon_sym_i8] = ACTIONS(509),
    [sym_is_external] = ACTIONS(509),
    [anon_sym_STAR_EQ] = ACTIONS(511),
    [anon_sym_PIPE] = ACTIONS(509),
    [anon_sym_DASH_DASH] = ACTIONS(509),
    [anon_sym_AMP_EQ] = ACTIONS(511),
    [anon_sym_CARET_EQ] = ACTIONS(511),
    [anon_sym_u16] = ACTIONS(509),
    [anon_sym_i16] = ACTIONS(509),
    [anon_sym_DASH] = ACTIONS(509),
    [anon_sym_EQ_EQ] = ACTIONS(511),
    [anon_sym_CARET] = ACTIONS(509),
    [anon_sym_LT] = ACTIONS(509),
    [anon_sym_PIPE_EQ] = ACTIONS(511),
    [sym__comment] = ACTIONS(3),
    [anon_sym_GT_GT_EQ] = ACTIONS(511),
    [anon_sym_u32] = ACTIONS(509),
    [anon_sym_f32] = ACTIONS(509),
    [anon_sym_i32] = ACTIONS(509),
    [anon_sym_AMP] = ACTIONS(509),
    [anon_sym_AMP_AMP] = ACTIONS(511),
    [anon_sym_GT] = ACTIONS(509),
    [anon_sym_GT_EQ] = ACTIONS(511),
    [anon_sym_RBRACE] = ACTIONS(511),
    [anon_sym_DOT] = ACTIONS(511),
    [sym_identifier] = ACTIONS(509),
    [anon_sym_COMMA] = ACTIONS(511),
    [anon_sym_LT_LT_EQ] = ACTIONS(511),
    [anon_sym_u64] = ACTIONS(509),
    [anon_sym_f64] = ACTIONS(509),
    [anon_sym_i64] = ACTIONS(509),
  },
  [172] = {
    [anon_sym_i8] = ACTIONS(437),
    [anon_sym_return] = ACTIONS(437),
    [sym_float] = ACTIONS(439),
    [anon_sym_s32] = ACTIONS(437),
    [sym_binary] = ACTIONS(439),
    [anon_sym_while] = ACTIONS(437),
    [sym_null] = ACTIONS(437),
    [anon_sym_DQUOTE] = ACTIONS(439),
    [sym_readonly] = ACTIONS(437),
    [anon_sym_protected] = ACTIONS(437),
    [anon_sym_u16] = ACTIONS(437),
    [anon_sym_s8] = ACTIONS(437),
    [sym_double] = ACTIONS(437),
    [anon_sym_i16] = ACTIONS(437),
    [anon_sym_goto] = ACTIONS(437),
    [anon_sym_LBRACE] = ACTIONS(439),
    [anon_sym_private] = ACTIONS(437),
    [sym__comment] = ACTIONS(3),
    [anon_sym_publish] = ACTIONS(437),
    [anon_sym_u32] = ACTIONS(437),
    [anon_sym_s16] = ACTIONS(437),
    [anon_sym_f32] = ACTIONS(437),
    [anon_sym_LPAREN] = ACTIONS(439),
    [anon_sym_i32] = ACTIONS(437),
    [sym_oct] = ACTIONS(437),
    [sym_long] = ACTIONS(439),
    [sym_hex] = ACTIONS(439),
    [anon_sym_section] = ACTIONS(437),
    [anon_sym_if] = ACTIONS(437),
    [anon_sym_DOT] = ACTIONS(437),
    [anon_sym_switch] = ACTIONS(437),
    [sym_identifier] = ACTIONS(437),
    [anon_sym_SQUOTE] = ACTIONS(439),
    [anon_sym_u64] = ACTIONS(437),
    [anon_sym_u8] = ACTIONS(437),
    [anon_sym_f64] = ACTIONS(437),
    [sym_integer] = ACTIONS(437),
    [anon_sym_i64] = ACTIONS(437),
  },
  [173] = {
    [sym__literal] = STATE(197),
    [sym_string] = STATE(197),
    [sym__value] = STATE(197),
    [sym__number] = STATE(197),
    [sym_group_expression] = STATE(197),
    [sym_character] = STATE(197),
    [sym_double] = ACTIONS(513),
    [sym_binary] = ACTIONS(515),
    [sym__comment] = ACTIONS(3),
    [sym_oct] = ACTIONS(513),
    [anon_sym_SQUOTE] = ACTIONS(88),
    [sym_identifier] = ACTIONS(513),
    [anon_sym_LPAREN] = ACTIONS(82),
    [sym_long] = ACTIONS(515),
    [sym_null] = ACTIONS(513),
    [sym_integer] = ACTIONS(513),
    [anon_sym_DQUOTE] = ACTIONS(74),
    [sym_float] = ACTIONS(515),
    [sym_hex] = ACTIONS(515),
  },
  [174] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_RPAREN] = ACTIONS(517),
  },
  [175] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_if] = ACTIONS(519),
  },
  [176] = {
    [sym_primitive_type] = STATE(16),
    [sym__control_flow_statement] = STATE(54),
    [sym_goto_statement] = STATE(54),
    [sym_switch_statement] = STATE(54),
    [aux_sym_function_definition_repeat1] = STATE(100),
    [sym_return_statement] = STATE(54),
    [sym_group_expression] = STATE(57),
    [sym__base_type] = STATE(16),
    [sym__literal] = STATE(55),
    [sym_type] = STATE(20),
    [sym_string] = STATE(55),
    [sym__statement] = STATE(100),
    [sym_access_control] = STATE(58),
    [sym_while_statement] = STATE(54),
    [sym_if_statement] = STATE(54),
    [sym_expression_statement] = STATE(54),
    [sym_variable_definition] = STATE(54),
    [sym__value] = STATE(55),
    [sym_collection] = STATE(60),
    [sym__number] = STATE(55),
    [sym_section_statement] = STATE(54),
    [sym_single_line_if_statement] = STATE(100),
    [sym__variable_statement] = STATE(54),
    [sym_assignment_expression] = STATE(59),
    [sym_end_if] = STATE(200),
    [sym__collection_or_value] = STATE(60),
    [sym_character] = STATE(55),
    [anon_sym_i8] = ACTIONS(22),
    [anon_sym_return] = ACTIONS(66),
    [anon_sym_i64] = ACTIONS(22),
    [anon_sym_s32] = ACTIONS(22),
    [sym_binary] = ACTIONS(68),
    [anon_sym_while] = ACTIONS(70),
    [sym_null] = ACTIONS(72),
    [anon_sym_DQUOTE] = ACTIONS(74),
    [sym_readonly] = ACTIONS(32),
    [anon_sym_protected] = ACTIONS(76),
    [anon_sym_u16] = ACTIONS(22),
    [anon_sym_s8] = ACTIONS(22),
    [sym_double] = ACTIONS(72),
    [anon_sym_i16] = ACTIONS(22),
    [anon_sym_goto] = ACTIONS(78),
    [anon_sym_LBRACE] = ACTIONS(80),
    [anon_sym_private] = ACTIONS(76),
    [sym__comment] = ACTIONS(3),
    [anon_sym_publish] = ACTIONS(76),
    [anon_sym_u32] = ACTIONS(22),
    [anon_sym_s16] = ACTIONS(22),
    [anon_sym_f32] = ACTIONS(22),
    [anon_sym_LPAREN] = ACTIONS(82),
    [anon_sym_i32] = ACTIONS(22),
    [sym_oct] = ACTIONS(72),
    [sym_long] = ACTIONS(68),
    [sym_hex] = ACTIONS(68),
    [anon_sym_section] = ACTIONS(84),
    [anon_sym_if] = ACTIONS(86),
    [anon_sym_SQUOTE] = ACTIONS(88),
    [sym_identifier] = ACTIONS(90),
    [anon_sym_switch] = ACTIONS(92),
    [anon_sym_end] = ACTIONS(453),
    [anon_sym_u64] = ACTIONS(22),
    [anon_sym_u8] = ACTIONS(22),
    [sym_float] = ACTIONS(68),
    [anon_sym_f64] = ACTIONS(22),
    [sym_integer] = ACTIONS(72),
  },
  [177] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(521),
  },
  [178] = {
    [sym_group_expression] = STATE(201),
    [sym__comment] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(82),
  },
  [179] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(523),
  },
  [180] = {
    [sym_end_switch] = STATE(204),
    [sym__comment] = ACTIONS(3),
    [anon_sym_end] = ACTIONS(525),
  },
  [181] = {
    [sym_case_statement] = STATE(206),
    [sym_default_statement] = STATE(205),
    [aux_sym_switch_statement_repeat1] = STATE(206),
    [sym__comment] = ACTIONS(3),
    [anon_sym_case] = ACTIONS(463),
    [anon_sym_default] = ACTIONS(465),
  },
  [182] = {
    [anon_sym_i8] = ACTIONS(488),
    [anon_sym_method] = ACTIONS(488),
    [anon_sym_private] = ACTIONS(488),
    [anon_sym_s32] = ACTIONS(488),
    [anon_sym_publish] = ACTIONS(488),
    [anon_sym_u32] = ACTIONS(488),
    [anon_sym_s16] = ACTIONS(488),
    [anon_sym_f32] = ACTIONS(488),
    [sym_is_external] = ACTIONS(488),
    [anon_sym_i32] = ACTIONS(488),
    [sym__comment] = ACTIONS(3),
    [anon_sym_function] = ACTIONS(488),
    [sym_readonly] = ACTIONS(488),
    [anon_sym_protected] = ACTIONS(488),
    [anon_sym_u16] = ACTIONS(488),
    [anon_sym_s8] = ACTIONS(488),
    [sym_is_declare] = ACTIONS(488),
    [anon_sym_enum] = ACTIONS(488),
    [anon_sym_i16] = ACTIONS(488),
    [sym_identifier] = ACTIONS(488),
    [anon_sym_end] = ACTIONS(488),
    [anon_sym_u64] = ACTIONS(488),
    [anon_sym_u8] = ACTIONS(488),
    [anon_sym_f64] = ACTIONS(488),
    [anon_sym_i64] = ACTIONS(488),
  },
  [183] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(527),
  },
  [184] = {
    [anon_sym_i8] = ACTIONS(529),
    [anon_sym_method] = ACTIONS(529),
    [anon_sym_private] = ACTIONS(529),
    [anon_sym_s32] = ACTIONS(529),
    [anon_sym_publish] = ACTIONS(529),
    [anon_sym_u32] = ACTIONS(529),
    [anon_sym_s16] = ACTIONS(529),
    [anon_sym_f32] = ACTIONS(529),
    [sym_is_external] = ACTIONS(529),
    [anon_sym_i32] = ACTIONS(529),
    [sym__comment] = ACTIONS(3),
    [anon_sym_function] = ACTIONS(529),
    [sym_readonly] = ACTIONS(529),
    [anon_sym_protected] = ACTIONS(529),
    [anon_sym_u16] = ACTIONS(529),
    [anon_sym_s8] = ACTIONS(529),
    [sym_is_declare] = ACTIONS(529),
    [anon_sym_enum] = ACTIONS(529),
    [anon_sym_i16] = ACTIONS(529),
    [sym_identifier] = ACTIONS(529),
    [anon_sym_end] = ACTIONS(529),
    [anon_sym_u64] = ACTIONS(529),
    [anon_sym_u8] = ACTIONS(529),
    [anon_sym_f64] = ACTIONS(529),
    [anon_sym_i64] = ACTIONS(529),
  },
  [185] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(531),
  },
  [186] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(533),
    [anon_sym_RPAREN] = ACTIONS(533),
  },
  [187] = {
    [aux_sym__comma_list_variables_repeat1] = STATE(187),
    [sym__comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(535),
    [anon_sym_RPAREN] = ACTIONS(533),
  },
  [188] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(538),
    [anon_sym_DOT] = ACTIONS(538),
  },
  [189] = {
    [aux_sym__comma_list_types_repeat1] = STATE(189),
    [sym__comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(540),
    [anon_sym_DOT] = ACTIONS(538),
  },
  [190] = {
    [aux_sym_type_repeat2] = STATE(190),
    [sym_array] = STATE(190),
    [anon_sym_COMMA] = ACTIONS(226),
    [sym__comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(228),
    [anon_sym_DOT] = ACTIONS(226),
  },
  [191] = {
    [aux_sym_type_repeat2] = STATE(190),
    [sym_array] = STATE(190),
    [anon_sym_COMMA] = ACTIONS(231),
    [sym__comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(56),
    [anon_sym_DOT] = ACTIONS(231),
  },
  [192] = {
    [aux_sym_type_repeat1] = STATE(192),
    [sym_pointer] = STATE(192),
    [anon_sym_COMMA] = ACTIONS(233),
    [anon_sym_STAR] = ACTIONS(235),
    [sym__comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(233),
    [anon_sym_DOT] = ACTIONS(233),
  },
  [193] = {
    [anon_sym_i8] = ACTIONS(543),
    [anon_sym_return] = ACTIONS(543),
    [sym_float] = ACTIONS(545),
    [anon_sym_s32] = ACTIONS(543),
    [sym_binary] = ACTIONS(545),
    [anon_sym_while] = ACTIONS(543),
    [sym_null] = ACTIONS(543),
    [anon_sym_DQUOTE] = ACTIONS(545),
    [sym_readonly] = ACTIONS(543),
    [anon_sym_protected] = ACTIONS(543),
    [anon_sym_u16] = ACTIONS(543),
    [anon_sym_s8] = ACTIONS(543),
    [sym_double] = ACTIONS(543),
    [anon_sym_i16] = ACTIONS(543),
    [anon_sym_goto] = ACTIONS(543),
    [anon_sym_LBRACE] = ACTIONS(545),
    [anon_sym_private] = ACTIONS(543),
    [sym__comment] = ACTIONS(3),
    [anon_sym_publish] = ACTIONS(543),
    [anon_sym_u32] = ACTIONS(543),
    [anon_sym_s16] = ACTIONS(543),
    [anon_sym_f32] = ACTIONS(543),
    [anon_sym_LPAREN] = ACTIONS(545),
    [anon_sym_i32] = ACTIONS(543),
    [sym_oct] = ACTIONS(543),
    [sym_long] = ACTIONS(545),
    [sym_hex] = ACTIONS(545),
    [anon_sym_section] = ACTIONS(543),
    [anon_sym_if] = ACTIONS(543),
    [anon_sym_SQUOTE] = ACTIONS(545),
    [anon_sym_switch] = ACTIONS(543),
    [sym_identifier] = ACTIONS(543),
    [anon_sym_end] = ACTIONS(543),
    [anon_sym_u64] = ACTIONS(543),
    [anon_sym_u8] = ACTIONS(543),
    [anon_sym_f64] = ACTIONS(543),
    [sym_integer] = ACTIONS(543),
    [anon_sym_i64] = ACTIONS(543),
  },
  [194] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(547),
  },
  [195] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(549),
  },
  [196] = {
    [anon_sym_PLUS] = ACTIONS(551),
    [anon_sym_s32] = ACTIONS(551),
    [anon_sym_PIPE_PIPE] = ACTIONS(553),
    [anon_sym_LT_LT] = ACTIONS(551),
    [anon_sym_LT_EQ] = ACTIONS(553),
    [anon_sym_function] = ACTIONS(551),
    [sym_readonly] = ACTIONS(551),
    [anon_sym_PLUS_PLUS] = ACTIONS(553),
    [anon_sym_protected] = ACTIONS(551),
    [anon_sym_s8] = ACTIONS(551),
    [anon_sym_enum] = ACTIONS(551),
    [anon_sym_SLASH] = ACTIONS(551),
    [anon_sym_STAR] = ACTIONS(551),
    [anon_sym_GT_GT] = ACTIONS(551),
    [anon_sym_PLUS_EQ] = ACTIONS(553),
    [anon_sym_BANG_EQ] = ACTIONS(553),
    [anon_sym_method] = ACTIONS(551),
    [anon_sym_private] = ACTIONS(551),
    [anon_sym_SLASH_EQ] = ACTIONS(553),
    [anon_sym_publish] = ACTIONS(551),
    [anon_sym_s16] = ACTIONS(551),
    [anon_sym_COLON_EQ] = ACTIONS(553),
    [sym_is_declare] = ACTIONS(551),
    [anon_sym_DASH_EQ] = ACTIONS(553),
    [anon_sym_PERCENT] = ACTIONS(551),
    [anon_sym_PERCENT_EQ] = ACTIONS(553),
    [anon_sym_end] = ACTIONS(551),
    [anon_sym_u8] = ACTIONS(551),
    [anon_sym_RPAREN] = ACTIONS(553),
    [anon_sym_i8] = ACTIONS(551),
    [sym_is_external] = ACTIONS(551),
    [anon_sym_STAR_EQ] = ACTIONS(553),
    [anon_sym_PIPE] = ACTIONS(551),
    [anon_sym_DASH_DASH] = ACTIONS(551),
    [anon_sym_AMP_EQ] = ACTIONS(553),
    [anon_sym_CARET_EQ] = ACTIONS(553),
    [anon_sym_u16] = ACTIONS(551),
    [anon_sym_i16] = ACTIONS(551),
    [anon_sym_DASH] = ACTIONS(551),
    [anon_sym_EQ_EQ] = ACTIONS(553),
    [anon_sym_CARET] = ACTIONS(551),
    [anon_sym_LT] = ACTIONS(551),
    [anon_sym_PIPE_EQ] = ACTIONS(553),
    [sym__comment] = ACTIONS(3),
    [anon_sym_GT_GT_EQ] = ACTIONS(553),
    [anon_sym_u32] = ACTIONS(551),
    [anon_sym_f32] = ACTIONS(551),
    [anon_sym_i32] = ACTIONS(551),
    [anon_sym_AMP] = ACTIONS(551),
    [anon_sym_AMP_AMP] = ACTIONS(553),
    [anon_sym_GT] = ACTIONS(551),
    [anon_sym_GT_EQ] = ACTIONS(553),
    [anon_sym_RBRACE] = ACTIONS(553),
    [anon_sym_DOT] = ACTIONS(553),
    [sym_identifier] = ACTIONS(551),
    [anon_sym_COMMA] = ACTIONS(553),
    [anon_sym_LT_LT_EQ] = ACTIONS(553),
    [anon_sym_u64] = ACTIONS(551),
    [anon_sym_f64] = ACTIONS(551),
    [anon_sym_i64] = ACTIONS(551),
  },
  [197] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_RPAREN] = ACTIONS(555),
  },
  [198] = {
    [anon_sym_i8] = ACTIONS(509),
    [anon_sym_return] = ACTIONS(509),
    [sym_float] = ACTIONS(511),
    [anon_sym_s32] = ACTIONS(509),
    [sym_binary] = ACTIONS(511),
    [anon_sym_while] = ACTIONS(509),
    [sym_null] = ACTIONS(509),
    [anon_sym_DQUOTE] = ACTIONS(511),
    [sym_readonly] = ACTIONS(509),
    [anon_sym_protected] = ACTIONS(509),
    [anon_sym_u16] = ACTIONS(509),
    [anon_sym_s8] = ACTIONS(509),
    [sym_double] = ACTIONS(509),
    [anon_sym_i16] = ACTIONS(509),
    [anon_sym_goto] = ACTIONS(509),
    [anon_sym_LBRACE] = ACTIONS(511),
    [anon_sym_private] = ACTIONS(509),
    [sym__comment] = ACTIONS(3),
    [anon_sym_publish] = ACTIONS(509),
    [anon_sym_u32] = ACTIONS(509),
    [anon_sym_s16] = ACTIONS(509),
    [anon_sym_f32] = ACTIONS(509),
    [anon_sym_LPAREN] = ACTIONS(511),
    [anon_sym_i32] = ACTIONS(509),
    [sym_oct] = ACTIONS(509),
    [sym_long] = ACTIONS(511),
    [sym_hex] = ACTIONS(511),
    [anon_sym_section] = ACTIONS(509),
    [anon_sym_if] = ACTIONS(509),
    [anon_sym_DOT] = ACTIONS(509),
    [anon_sym_switch] = ACTIONS(509),
    [sym_identifier] = ACTIONS(509),
    [anon_sym_SQUOTE] = ACTIONS(511),
    [anon_sym_u64] = ACTIONS(509),
    [anon_sym_u8] = ACTIONS(509),
    [anon_sym_f64] = ACTIONS(509),
    [sym_integer] = ACTIONS(509),
    [anon_sym_i64] = ACTIONS(509),
  },
  [199] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(557),
  },
  [200] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(559),
  },
  [201] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(561),
  },
  [202] = {
    [sym_primitive_type] = STATE(16),
    [sym__control_flow_statement] = STATE(54),
    [sym_goto_statement] = STATE(54),
    [sym_switch_statement] = STATE(54),
    [aux_sym_function_definition_repeat1] = STATE(212),
    [sym_return_statement] = STATE(54),
    [sym_group_expression] = STATE(57),
    [sym_end_default] = STATE(213),
    [sym__base_type] = STATE(16),
    [sym__literal] = STATE(55),
    [sym_type] = STATE(20),
    [sym_string] = STATE(55),
    [sym__statement] = STATE(212),
    [sym_access_control] = STATE(58),
    [sym_while_statement] = STATE(54),
    [sym_if_statement] = STATE(54),
    [sym_expression_statement] = STATE(54),
    [sym_variable_definition] = STATE(54),
    [sym__value] = STATE(55),
    [sym_collection] = STATE(60),
    [sym__number] = STATE(55),
    [sym_section_statement] = STATE(54),
    [sym_single_line_if_statement] = STATE(212),
    [sym__variable_statement] = STATE(54),
    [sym_assignment_expression] = STATE(59),
    [sym__collection_or_value] = STATE(60),
    [sym_character] = STATE(55),
    [anon_sym_i8] = ACTIONS(22),
    [anon_sym_return] = ACTIONS(66),
    [anon_sym_i64] = ACTIONS(22),
    [anon_sym_s32] = ACTIONS(22),
    [sym_binary] = ACTIONS(68),
    [anon_sym_while] = ACTIONS(70),
    [sym_null] = ACTIONS(72),
    [anon_sym_DQUOTE] = ACTIONS(74),
    [sym_readonly] = ACTIONS(32),
    [anon_sym_protected] = ACTIONS(76),
    [anon_sym_u16] = ACTIONS(22),
    [anon_sym_s8] = ACTIONS(22),
    [sym_double] = ACTIONS(72),
    [anon_sym_i16] = ACTIONS(22),
    [anon_sym_goto] = ACTIONS(78),
    [anon_sym_LBRACE] = ACTIONS(80),
    [anon_sym_private] = ACTIONS(76),
    [sym__comment] = ACTIONS(3),
    [anon_sym_publish] = ACTIONS(76),
    [anon_sym_u32] = ACTIONS(22),
    [anon_sym_s16] = ACTIONS(22),
    [anon_sym_f32] = ACTIONS(22),
    [anon_sym_LPAREN] = ACTIONS(82),
    [anon_sym_i32] = ACTIONS(22),
    [sym_oct] = ACTIONS(72),
    [sym_long] = ACTIONS(68),
    [sym_hex] = ACTIONS(68),
    [anon_sym_section] = ACTIONS(84),
    [anon_sym_if] = ACTIONS(86),
    [anon_sym_SQUOTE] = ACTIONS(88),
    [sym_identifier] = ACTIONS(90),
    [anon_sym_switch] = ACTIONS(92),
    [anon_sym_end] = ACTIONS(563),
    [anon_sym_u64] = ACTIONS(22),
    [anon_sym_u8] = ACTIONS(22),
    [sym_float] = ACTIONS(68),
    [anon_sym_f64] = ACTIONS(22),
    [sym_integer] = ACTIONS(72),
  },
  [203] = {
    [anon_sym_switch] = ACTIONS(565),
    [sym__comment] = ACTIONS(3),
  },
  [204] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(567),
  },
  [205] = {
    [sym_end_switch] = STATE(215),
    [sym__comment] = ACTIONS(3),
    [anon_sym_end] = ACTIONS(525),
  },
  [206] = {
    [sym_case_statement] = STATE(206),
    [aux_sym_switch_statement_repeat1] = STATE(206),
    [sym__comment] = ACTIONS(3),
    [anon_sym_case] = ACTIONS(569),
    [anon_sym_default] = ACTIONS(572),
  },
  [207] = {
    [anon_sym_i8] = ACTIONS(543),
    [anon_sym_method] = ACTIONS(543),
    [anon_sym_private] = ACTIONS(543),
    [anon_sym_s32] = ACTIONS(543),
    [anon_sym_publish] = ACTIONS(543),
    [anon_sym_u32] = ACTIONS(543),
    [anon_sym_s16] = ACTIONS(543),
    [anon_sym_f32] = ACTIONS(543),
    [sym_is_external] = ACTIONS(543),
    [anon_sym_i32] = ACTIONS(543),
    [sym__comment] = ACTIONS(3),
    [anon_sym_function] = ACTIONS(543),
    [sym_readonly] = ACTIONS(543),
    [anon_sym_protected] = ACTIONS(543),
    [anon_sym_u16] = ACTIONS(543),
    [anon_sym_s8] = ACTIONS(543),
    [sym_is_declare] = ACTIONS(543),
    [anon_sym_enum] = ACTIONS(543),
    [anon_sym_i16] = ACTIONS(543),
    [sym_identifier] = ACTIONS(543),
    [anon_sym_end] = ACTIONS(543),
    [anon_sym_u64] = ACTIONS(543),
    [anon_sym_u8] = ACTIONS(543),
    [anon_sym_f64] = ACTIONS(543),
    [anon_sym_i64] = ACTIONS(543),
  },
  [208] = {
    [anon_sym_i8] = ACTIONS(574),
    [anon_sym_method] = ACTIONS(574),
    [anon_sym_private] = ACTIONS(574),
    [anon_sym_s32] = ACTIONS(574),
    [anon_sym_publish] = ACTIONS(574),
    [anon_sym_u32] = ACTIONS(574),
    [anon_sym_s16] = ACTIONS(574),
    [anon_sym_f32] = ACTIONS(574),
    [sym_is_external] = ACTIONS(574),
    [anon_sym_i32] = ACTIONS(574),
    [sym__comment] = ACTIONS(3),
    [anon_sym_function] = ACTIONS(574),
    [sym_readonly] = ACTIONS(574),
    [anon_sym_protected] = ACTIONS(574),
    [anon_sym_u16] = ACTIONS(574),
    [anon_sym_s8] = ACTIONS(574),
    [sym_is_declare] = ACTIONS(574),
    [anon_sym_enum] = ACTIONS(574),
    [anon_sym_i16] = ACTIONS(574),
    [sym_identifier] = ACTIONS(574),
    [anon_sym_end] = ACTIONS(574),
    [anon_sym_u64] = ACTIONS(574),
    [anon_sym_u8] = ACTIONS(574),
    [anon_sym_f64] = ACTIONS(574),
    [anon_sym_i64] = ACTIONS(574),
  },
  [209] = {
    [anon_sym_i8] = ACTIONS(551),
    [anon_sym_return] = ACTIONS(551),
    [sym_float] = ACTIONS(553),
    [anon_sym_s32] = ACTIONS(551),
    [sym_binary] = ACTIONS(553),
    [anon_sym_while] = ACTIONS(551),
    [sym_null] = ACTIONS(551),
    [anon_sym_DQUOTE] = ACTIONS(553),
    [sym_readonly] = ACTIONS(551),
    [anon_sym_protected] = ACTIONS(551),
    [anon_sym_u16] = ACTIONS(551),
    [anon_sym_s8] = ACTIONS(551),
    [sym_double] = ACTIONS(551),
    [anon_sym_i16] = ACTIONS(551),
    [anon_sym_goto] = ACTIONS(551),
    [anon_sym_LBRACE] = ACTIONS(553),
    [anon_sym_private] = ACTIONS(551),
    [sym__comment] = ACTIONS(3),
    [anon_sym_publish] = ACTIONS(551),
    [anon_sym_u32] = ACTIONS(551),
    [anon_sym_s16] = ACTIONS(551),
    [anon_sym_f32] = ACTIONS(551),
    [anon_sym_LPAREN] = ACTIONS(553),
    [anon_sym_i32] = ACTIONS(551),
    [sym_oct] = ACTIONS(551),
    [sym_long] = ACTIONS(553),
    [sym_hex] = ACTIONS(553),
    [anon_sym_section] = ACTIONS(551),
    [anon_sym_if] = ACTIONS(551),
    [anon_sym_DOT] = ACTIONS(551),
    [anon_sym_switch] = ACTIONS(551),
    [sym_identifier] = ACTIONS(551),
    [anon_sym_SQUOTE] = ACTIONS(553),
    [anon_sym_u64] = ACTIONS(551),
    [anon_sym_u8] = ACTIONS(551),
    [anon_sym_f64] = ACTIONS(551),
    [sym_integer] = ACTIONS(551),
    [anon_sym_i64] = ACTIONS(551),
  },
  [210] = {
    [sym_primitive_type] = STATE(16),
    [sym__control_flow_statement] = STATE(54),
    [sym_goto_statement] = STATE(54),
    [sym_switch_statement] = STATE(54),
    [aux_sym_function_definition_repeat1] = STATE(217),
    [sym_return_statement] = STATE(54),
    [sym_group_expression] = STATE(57),
    [sym_end_case] = STATE(218),
    [sym__base_type] = STATE(16),
    [sym__literal] = STATE(55),
    [sym_type] = STATE(20),
    [sym_string] = STATE(55),
    [sym__statement] = STATE(217),
    [sym_access_control] = STATE(58),
    [sym_while_statement] = STATE(54),
    [sym_if_statement] = STATE(54),
    [sym_expression_statement] = STATE(54),
    [sym_variable_definition] = STATE(54),
    [sym__value] = STATE(55),
    [sym_collection] = STATE(60),
    [sym__number] = STATE(55),
    [sym_section_statement] = STATE(54),
    [sym_single_line_if_statement] = STATE(217),
    [sym__variable_statement] = STATE(54),
    [sym_assignment_expression] = STATE(59),
    [sym__collection_or_value] = STATE(60),
    [sym_character] = STATE(55),
    [anon_sym_i8] = ACTIONS(22),
    [anon_sym_return] = ACTIONS(66),
    [anon_sym_i64] = ACTIONS(22),
    [anon_sym_s32] = ACTIONS(22),
    [sym_binary] = ACTIONS(68),
    [anon_sym_while] = ACTIONS(70),
    [sym_null] = ACTIONS(72),
    [anon_sym_DQUOTE] = ACTIONS(74),
    [sym_readonly] = ACTIONS(32),
    [anon_sym_protected] = ACTIONS(76),
    [anon_sym_u16] = ACTIONS(22),
    [anon_sym_s8] = ACTIONS(22),
    [sym_double] = ACTIONS(72),
    [anon_sym_i16] = ACTIONS(22),
    [anon_sym_goto] = ACTIONS(78),
    [anon_sym_LBRACE] = ACTIONS(80),
    [anon_sym_private] = ACTIONS(76),
    [sym__comment] = ACTIONS(3),
    [anon_sym_publish] = ACTIONS(76),
    [anon_sym_u32] = ACTIONS(22),
    [anon_sym_s16] = ACTIONS(22),
    [anon_sym_f32] = ACTIONS(22),
    [anon_sym_LPAREN] = ACTIONS(82),
    [anon_sym_i32] = ACTIONS(22),
    [sym_oct] = ACTIONS(72),
    [sym_long] = ACTIONS(68),
    [sym_hex] = ACTIONS(68),
    [anon_sym_section] = ACTIONS(84),
    [anon_sym_if] = ACTIONS(86),
    [anon_sym_SQUOTE] = ACTIONS(88),
    [sym_identifier] = ACTIONS(90),
    [anon_sym_switch] = ACTIONS(92),
    [anon_sym_end] = ACTIONS(576),
    [anon_sym_u64] = ACTIONS(22),
    [anon_sym_u8] = ACTIONS(22),
    [sym_float] = ACTIONS(68),
    [anon_sym_f64] = ACTIONS(22),
    [sym_integer] = ACTIONS(72),
  },
  [211] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_default] = ACTIONS(578),
  },
  [212] = {
    [sym_primitive_type] = STATE(16),
    [sym__control_flow_statement] = STATE(54),
    [sym_goto_statement] = STATE(54),
    [sym_switch_statement] = STATE(54),
    [aux_sym_function_definition_repeat1] = STATE(100),
    [sym_return_statement] = STATE(54),
    [sym_group_expression] = STATE(57),
    [sym_end_default] = STATE(220),
    [sym__base_type] = STATE(16),
    [sym__literal] = STATE(55),
    [sym_type] = STATE(20),
    [sym_string] = STATE(55),
    [sym__statement] = STATE(100),
    [sym_access_control] = STATE(58),
    [sym_while_statement] = STATE(54),
    [sym_if_statement] = STATE(54),
    [sym_expression_statement] = STATE(54),
    [sym_variable_definition] = STATE(54),
    [sym__value] = STATE(55),
    [sym_collection] = STATE(60),
    [sym__number] = STATE(55),
    [sym_section_statement] = STATE(54),
    [sym_single_line_if_statement] = STATE(100),
    [sym__variable_statement] = STATE(54),
    [sym_assignment_expression] = STATE(59),
    [sym__collection_or_value] = STATE(60),
    [sym_character] = STATE(55),
    [anon_sym_i8] = ACTIONS(22),
    [anon_sym_return] = ACTIONS(66),
    [anon_sym_i64] = ACTIONS(22),
    [anon_sym_s32] = ACTIONS(22),
    [sym_binary] = ACTIONS(68),
    [anon_sym_while] = ACTIONS(70),
    [sym_null] = ACTIONS(72),
    [anon_sym_DQUOTE] = ACTIONS(74),
    [sym_readonly] = ACTIONS(32),
    [anon_sym_protected] = ACTIONS(76),
    [anon_sym_u16] = ACTIONS(22),
    [anon_sym_s8] = ACTIONS(22),
    [sym_double] = ACTIONS(72),
    [anon_sym_i16] = ACTIONS(22),
    [anon_sym_goto] = ACTIONS(78),
    [anon_sym_LBRACE] = ACTIONS(80),
    [anon_sym_private] = ACTIONS(76),
    [sym__comment] = ACTIONS(3),
    [anon_sym_publish] = ACTIONS(76),
    [anon_sym_u32] = ACTIONS(22),
    [anon_sym_s16] = ACTIONS(22),
    [anon_sym_f32] = ACTIONS(22),
    [anon_sym_LPAREN] = ACTIONS(82),
    [anon_sym_i32] = ACTIONS(22),
    [sym_oct] = ACTIONS(72),
    [sym_long] = ACTIONS(68),
    [sym_hex] = ACTIONS(68),
    [anon_sym_section] = ACTIONS(84),
    [anon_sym_if] = ACTIONS(86),
    [anon_sym_SQUOTE] = ACTIONS(88),
    [sym_identifier] = ACTIONS(90),
    [anon_sym_switch] = ACTIONS(92),
    [anon_sym_end] = ACTIONS(563),
    [anon_sym_u64] = ACTIONS(22),
    [anon_sym_u8] = ACTIONS(22),
    [sym_float] = ACTIONS(68),
    [anon_sym_f64] = ACTIONS(22),
    [sym_integer] = ACTIONS(72),
  },
  [213] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(580),
  },
  [214] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(582),
  },
  [215] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(584),
  },
  [216] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_case] = ACTIONS(586),
  },
  [217] = {
    [sym_primitive_type] = STATE(16),
    [sym__control_flow_statement] = STATE(54),
    [sym_goto_statement] = STATE(54),
    [sym_switch_statement] = STATE(54),
    [aux_sym_function_definition_repeat1] = STATE(100),
    [sym_return_statement] = STATE(54),
    [sym_group_expression] = STATE(57),
    [sym_end_case] = STATE(223),
    [sym__base_type] = STATE(16),
    [sym__literal] = STATE(55),
    [sym_type] = STATE(20),
    [sym_string] = STATE(55),
    [sym__statement] = STATE(100),
    [sym_access_control] = STATE(58),
    [sym_while_statement] = STATE(54),
    [sym_if_statement] = STATE(54),
    [sym_expression_statement] = STATE(54),
    [sym_variable_definition] = STATE(54),
    [sym__value] = STATE(55),
    [sym_collection] = STATE(60),
    [sym__number] = STATE(55),
    [sym_section_statement] = STATE(54),
    [sym_single_line_if_statement] = STATE(100),
    [sym__variable_statement] = STATE(54),
    [sym_assignment_expression] = STATE(59),
    [sym__collection_or_value] = STATE(60),
    [sym_character] = STATE(55),
    [anon_sym_i8] = ACTIONS(22),
    [anon_sym_return] = ACTIONS(66),
    [anon_sym_i64] = ACTIONS(22),
    [anon_sym_s32] = ACTIONS(22),
    [sym_binary] = ACTIONS(68),
    [anon_sym_while] = ACTIONS(70),
    [sym_null] = ACTIONS(72),
    [anon_sym_DQUOTE] = ACTIONS(74),
    [sym_readonly] = ACTIONS(32),
    [anon_sym_protected] = ACTIONS(76),
    [anon_sym_u16] = ACTIONS(22),
    [anon_sym_s8] = ACTIONS(22),
    [sym_double] = ACTIONS(72),
    [anon_sym_i16] = ACTIONS(22),
    [anon_sym_goto] = ACTIONS(78),
    [anon_sym_LBRACE] = ACTIONS(80),
    [anon_sym_private] = ACTIONS(76),
    [sym__comment] = ACTIONS(3),
    [anon_sym_publish] = ACTIONS(76),
    [anon_sym_u32] = ACTIONS(22),
    [anon_sym_s16] = ACTIONS(22),
    [anon_sym_f32] = ACTIONS(22),
    [anon_sym_LPAREN] = ACTIONS(82),
    [anon_sym_i32] = ACTIONS(22),
    [sym_oct] = ACTIONS(72),
    [sym_long] = ACTIONS(68),
    [sym_hex] = ACTIONS(68),
    [anon_sym_section] = ACTIONS(84),
    [anon_sym_if] = ACTIONS(86),
    [anon_sym_SQUOTE] = ACTIONS(88),
    [sym_identifier] = ACTIONS(90),
    [anon_sym_switch] = ACTIONS(92),
    [anon_sym_end] = ACTIONS(576),
    [anon_sym_u64] = ACTIONS(22),
    [anon_sym_u8] = ACTIONS(22),
    [sym_float] = ACTIONS(68),
    [anon_sym_f64] = ACTIONS(22),
    [sym_integer] = ACTIONS(72),
  },
  [218] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(588),
  },
  [219] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(590),
  },
  [220] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(592),
  },
  [221] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_end] = ACTIONS(594),
  },
  [222] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(596),
  },
  [223] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(598),
  },
  [224] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_case] = ACTIONS(600),
    [anon_sym_default] = ACTIONS(600),
  },
  [225] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_end] = ACTIONS(602),
  },
  [226] = {
    [sym__comment] = ACTIONS(3),
    [anon_sym_case] = ACTIONS(604),
    [anon_sym_default] = ACTIONS(604),
  },
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.count = 0, .reusable = false},
  [1] = {.count = 1, .reusable = false}, RECOVER(),
  [3] = {.count = 1, .reusable = true}, SHIFT_EXTRA(),
  [5] = {.count = 1, .reusable = true}, REDUCE(sym_source_file, 0),
  [7] = {.count = 1, .reusable = true}, SHIFT(2),
  [9] = {.count = 1, .reusable = true}, SHIFT(5),
  [11] = {.count = 1, .reusable = true},  ACCEPT_INPUT(),
  [13] = {.count = 1, .reusable = true}, REDUCE(sym_source_file, 1),
  [15] = {.count = 1, .reusable = true}, SHIFT(7),
  [17] = {.count = 1, .reusable = true}, REDUCE(aux_sym_source_file_repeat1, 2),
  [19] = {.count = 2, .reusable = true}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(2),
  [22] = {.count = 1, .reusable = false}, SHIFT(8),
  [24] = {.count = 1, .reusable = false}, SHIFT(9),
  [26] = {.count = 1, .reusable = false}, SHIFT(10),
  [28] = {.count = 1, .reusable = false}, SHIFT(11),
  [30] = {.count = 1, .reusable = false}, SHIFT(12),
  [32] = {.count = 1, .reusable = false}, SHIFT(13),
  [34] = {.count = 1, .reusable = false}, SHIFT(14),
  [36] = {.count = 1, .reusable = false}, SHIFT(16),
  [38] = {.count = 1, .reusable = false}, SHIFT(15),
  [40] = {.count = 1, .reusable = true}, REDUCE(sym_primitive_type, 1),
  [42] = {.count = 1, .reusable = true}, REDUCE(sym_is_method, 1),
  [44] = {.count = 1, .reusable = false}, REDUCE(sym_access_control, 1),
  [46] = {.count = 1, .reusable = true}, REDUCE(sym_is_function, 1),
  [48] = {.count = 1, .reusable = true}, SHIFT(27),
  [50] = {.count = 1, .reusable = true}, SHIFT(28),
  [52] = {.count = 1, .reusable = true}, REDUCE(sym_type, 1),
  [54] = {.count = 1, .reusable = true}, SHIFT(29),
  [56] = {.count = 1, .reusable = true}, SHIFT(30),
  [58] = {.count = 1, .reusable = true}, SHIFT(35),
  [60] = {.count = 1, .reusable = true}, SHIFT(36),
  [62] = {.count = 1, .reusable = true}, SHIFT(37),
  [64] = {.count = 1, .reusable = false}, SHIFT(38),
  [66] = {.count = 1, .reusable = false}, SHIFT(40),
  [68] = {.count = 1, .reusable = true}, SHIFT(55),
  [70] = {.count = 1, .reusable = false}, SHIFT(41),
  [72] = {.count = 1, .reusable = false}, SHIFT(55),
  [74] = {.count = 1, .reusable = true}, SHIFT(42),
  [76] = {.count = 1, .reusable = false}, SHIFT(43),
  [78] = {.count = 1, .reusable = false}, SHIFT(44),
  [80] = {.count = 1, .reusable = true}, SHIFT(45),
  [82] = {.count = 1, .reusable = true}, SHIFT(46),
  [84] = {.count = 1, .reusable = false}, SHIFT(47),
  [86] = {.count = 1, .reusable = false}, SHIFT(48),
  [88] = {.count = 1, .reusable = true}, SHIFT(49),
  [90] = {.count = 1, .reusable = false}, SHIFT(50),
  [92] = {.count = 1, .reusable = false}, SHIFT(51),
  [94] = {.count = 1, .reusable = false}, SHIFT(52),
  [96] = {.count = 1, .reusable = false}, REDUCE(sym_declaration_definition, 2),
  [98] = {.count = 1, .reusable = true}, SHIFT(61),
  [100] = {.count = 1, .reusable = true}, SHIFT(63),
  [102] = {.count = 1, .reusable = true}, SHIFT(64),
  [104] = {.count = 1, .reusable = true}, REDUCE(sym_end_module, 2),
  [106] = {.count = 1, .reusable = true}, REDUCE(sym_pointer, 1),
  [108] = {.count = 1, .reusable = true}, SHIFT(67),
  [110] = {.count = 1, .reusable = true}, SHIFT(66),
  [112] = {.count = 1, .reusable = true}, REDUCE(sym_type, 2),
  [114] = {.count = 2, .reusable = false}, REDUCE(aux_sym_module_definition_repeat1, 2), SHIFT_REPEAT(8),
  [117] = {.count = 2, .reusable = false}, REDUCE(aux_sym_module_definition_repeat1, 2), SHIFT_REPEAT(9),
  [120] = {.count = 2, .reusable = false}, REDUCE(aux_sym_module_definition_repeat1, 2), SHIFT_REPEAT(10),
  [123] = {.count = 2, .reusable = false}, REDUCE(aux_sym_module_definition_repeat1, 2), SHIFT_REPEAT(11),
  [126] = {.count = 2, .reusable = false}, REDUCE(aux_sym_module_definition_repeat1, 2), SHIFT_REPEAT(12),
  [129] = {.count = 2, .reusable = false}, REDUCE(aux_sym_module_definition_repeat1, 2), SHIFT_REPEAT(13),
  [132] = {.count = 2, .reusable = false}, REDUCE(aux_sym_module_definition_repeat1, 2), SHIFT_REPEAT(14),
  [135] = {.count = 2, .reusable = false}, REDUCE(aux_sym_module_definition_repeat1, 2), SHIFT_REPEAT(16),
  [138] = {.count = 1, .reusable = false}, REDUCE(aux_sym_module_definition_repeat1, 2),
  [140] = {.count = 1, .reusable = true}, SHIFT(71),
  [142] = {.count = 1, .reusable = true}, REDUCE(sym_module_definition, 5),
  [144] = {.count = 1, .reusable = true}, SHIFT(73),
  [146] = {.count = 1, .reusable = true}, SHIFT(74),
  [148] = {.count = 1, .reusable = true}, SHIFT(72),
  [150] = {.count = 1, .reusable = false}, REDUCE(sym_variable_definition, 2),
  [152] = {.count = 1, .reusable = true}, SHIFT(77),
  [154] = {.count = 1, .reusable = true}, REDUCE(sym_variable_definition, 2),
  [156] = {.count = 1, .reusable = true}, SHIFT(80),
  [158] = {.count = 1, .reusable = false}, SHIFT_EXTRA(),
  [160] = {.count = 1, .reusable = false}, SHIFT(84),
  [162] = {.count = 1, .reusable = false}, SHIFT(85),
  [164] = {.count = 1, .reusable = true}, SHIFT(86),
  [166] = {.count = 1, .reusable = true}, SHIFT(90),
  [168] = {.count = 1, .reusable = false}, SHIFT(90),
  [170] = {.count = 1, .reusable = true}, SHIFT(89),
  [172] = {.count = 1, .reusable = false}, SHIFT(89),
  [174] = {.count = 1, .reusable = true}, SHIFT(93),
  [176] = {.count = 1, .reusable = true}, SHIFT(94),
  [178] = {.count = 1, .reusable = true}, SHIFT(96),
  [180] = {.count = 1, .reusable = false}, SHIFT(96),
  [182] = {.count = 1, .reusable = true}, REDUCE(sym__value, 1),
  [184] = {.count = 1, .reusable = false}, REDUCE(sym__value, 1),
  [186] = {.count = 1, .reusable = true}, REDUCE(sym__base_type, 1),
  [188] = {.count = 1, .reusable = false}, REDUCE(sym__base_type, 1),
  [190] = {.count = 1, .reusable = true}, SHIFT(98),
  [192] = {.count = 1, .reusable = true}, SHIFT(99),
  [194] = {.count = 1, .reusable = true}, SHIFT(102),
  [196] = {.count = 1, .reusable = true}, REDUCE(sym__collection_or_value, 1),
  [198] = {.count = 1, .reusable = false}, SHIFT(103),
  [200] = {.count = 1, .reusable = true}, SHIFT(103),
  [202] = {.count = 1, .reusable = true}, SHIFT(105),
  [204] = {.count = 1, .reusable = true}, REDUCE(sym_expression_statement, 1),
  [206] = {.count = 1, .reusable = true}, SHIFT(106),
  [208] = {.count = 1, .reusable = true}, SHIFT(108),
  [210] = {.count = 1, .reusable = true}, SHIFT(111),
  [212] = {.count = 1, .reusable = false}, REDUCE(sym_variable_definition, 3),
  [214] = {.count = 1, .reusable = true}, REDUCE(sym_variable_definition, 3),
  [216] = {.count = 1, .reusable = true}, REDUCE(sym__enum_element, 1),
  [218] = {.count = 1, .reusable = true}, SHIFT(114),
  [220] = {.count = 1, .reusable = true}, SHIFT(115),
  [222] = {.count = 1, .reusable = true}, SHIFT(117),
  [224] = {.count = 1, .reusable = true}, REDUCE(sym_array, 2),
  [226] = {.count = 1, .reusable = true}, REDUCE(aux_sym_type_repeat2, 2),
  [228] = {.count = 2, .reusable = true}, REDUCE(aux_sym_type_repeat2, 2), SHIFT_REPEAT(30),
  [231] = {.count = 1, .reusable = true}, REDUCE(sym_type, 3),
  [233] = {.count = 1, .reusable = true}, REDUCE(aux_sym_type_repeat1, 2),
  [235] = {.count = 2, .reusable = true}, REDUCE(aux_sym_type_repeat1, 2), SHIFT_REPEAT(29),
  [238] = {.count = 1, .reusable = true}, REDUCE(sym_module_definition, 6),
  [240] = {.count = 1, .reusable = false}, REDUCE(sym_function_signature, 3),
  [242] = {.count = 1, .reusable = true}, REDUCE(sym_function_signature, 3),
  [244] = {.count = 1, .reusable = true}, SHIFT(118),
  [246] = {.count = 1, .reusable = false}, SHIFT(123),
  [248] = {.count = 1, .reusable = true}, SHIFT(124),
  [250] = {.count = 1, .reusable = false}, SHIFT(126),
  [252] = {.count = 1, .reusable = true}, SHIFT(126),
  [254] = {.count = 1, .reusable = true}, SHIFT(127),
  [256] = {.count = 1, .reusable = true}, REDUCE(sym_return_statement, 2),
  [258] = {.count = 1, .reusable = true}, REDUCE(sym__assignment_or_collection_or_value, 1),
  [260] = {.count = 1, .reusable = true}, SHIFT(129),
  [262] = {.count = 1, .reusable = false}, REDUCE(sym_string, 2),
  [264] = {.count = 1, .reusable = true}, REDUCE(sym_string, 2),
  [266] = {.count = 1, .reusable = false}, SHIFT(130),
  [268] = {.count = 1, .reusable = false}, SHIFT(131),
  [270] = {.count = 1, .reusable = true}, REDUCE(sym_goto_statement, 2),
  [272] = {.count = 1, .reusable = true}, SHIFT(132),
  [274] = {.count = 1, .reusable = true}, SHIFT(133),
  [276] = {.count = 1, .reusable = true}, REDUCE(sym__comma_list_assignment_or_collection_or_value, 1),
  [278] = {.count = 1, .reusable = false}, REDUCE(sym_unary_op, 1),
  [280] = {.count = 1, .reusable = true}, REDUCE(sym_unary_op, 1),
  [282] = {.count = 1, .reusable = false}, SHIFT(135),
  [284] = {.count = 1, .reusable = true}, SHIFT(135),
  [286] = {.count = 1, .reusable = true}, SHIFT(136),
  [288] = {.count = 1, .reusable = false}, SHIFT(138),
  [290] = {.count = 1, .reusable = true}, SHIFT(138),
  [292] = {.count = 1, .reusable = true}, REDUCE(sym_section_statement, 2),
  [294] = {.count = 1, .reusable = true}, SHIFT(139),
  [296] = {.count = 1, .reusable = false}, SHIFT(139),
  [298] = {.count = 1, .reusable = false}, SHIFT(142),
  [300] = {.count = 1, .reusable = true}, SHIFT(144),
  [302] = {.count = 1, .reusable = true}, SHIFT(145),
  [304] = {.count = 1, .reusable = true}, REDUCE(sym_end_function, 2),
  [306] = {.count = 1, .reusable = true}, REDUCE(sym_end_method, 2),
  [308] = {.count = 2, .reusable = false}, REDUCE(aux_sym_function_definition_repeat1, 2), SHIFT_REPEAT(8),
  [311] = {.count = 2, .reusable = false}, REDUCE(aux_sym_function_definition_repeat1, 2), SHIFT_REPEAT(40),
  [314] = {.count = 2, .reusable = true}, REDUCE(aux_sym_function_definition_repeat1, 2), SHIFT_REPEAT(55),
  [317] = {.count = 2, .reusable = false}, REDUCE(aux_sym_function_definition_repeat1, 2), SHIFT_REPEAT(41),
  [320] = {.count = 2, .reusable = false}, REDUCE(aux_sym_function_definition_repeat1, 2), SHIFT_REPEAT(55),
  [323] = {.count = 2, .reusable = true}, REDUCE(aux_sym_function_definition_repeat1, 2), SHIFT_REPEAT(42),
  [326] = {.count = 2, .reusable = false}, REDUCE(aux_sym_function_definition_repeat1, 2), SHIFT_REPEAT(13),
  [329] = {.count = 2, .reusable = false}, REDUCE(aux_sym_function_definition_repeat1, 2), SHIFT_REPEAT(43),
  [332] = {.count = 2, .reusable = false}, REDUCE(aux_sym_function_definition_repeat1, 2), SHIFT_REPEAT(44),
  [335] = {.count = 2, .reusable = true}, REDUCE(aux_sym_function_definition_repeat1, 2), SHIFT_REPEAT(45),
  [338] = {.count = 2, .reusable = true}, REDUCE(aux_sym_function_definition_repeat1, 2), SHIFT_REPEAT(46),
  [341] = {.count = 2, .reusable = false}, REDUCE(aux_sym_function_definition_repeat1, 2), SHIFT_REPEAT(47),
  [344] = {.count = 2, .reusable = false}, REDUCE(aux_sym_function_definition_repeat1, 2), SHIFT_REPEAT(48),
  [347] = {.count = 2, .reusable = true}, REDUCE(aux_sym_function_definition_repeat1, 2), SHIFT_REPEAT(49),
  [350] = {.count = 2, .reusable = false}, REDUCE(aux_sym_function_definition_repeat1, 2), SHIFT_REPEAT(51),
  [353] = {.count = 2, .reusable = false}, REDUCE(aux_sym_function_definition_repeat1, 2), SHIFT_REPEAT(50),
  [356] = {.count = 1, .reusable = false}, REDUCE(aux_sym_function_definition_repeat1, 2),
  [358] = {.count = 1, .reusable = true}, SHIFT(146),
  [360] = {.count = 1, .reusable = false}, REDUCE(sym__statement, 2),
  [362] = {.count = 1, .reusable = true}, REDUCE(sym__statement, 2),
  [364] = {.count = 1, .reusable = true}, REDUCE(sym_assignment_post_op, 1),
  [366] = {.count = 1, .reusable = true}, REDUCE(sym_assignment_expression, 2),
  [368] = {.count = 1, .reusable = false}, REDUCE(sym_function_definition, 3),
  [370] = {.count = 1, .reusable = true}, REDUCE(sym_assignment_op, 1),
  [372] = {.count = 1, .reusable = false}, REDUCE(sym_assignment_op, 1),
  [374] = {.count = 1, .reusable = false}, SHIFT(147),
  [376] = {.count = 1, .reusable = true}, SHIFT(147),
  [378] = {.count = 1, .reusable = true}, SHIFT(148),
  [380] = {.count = 1, .reusable = false}, REDUCE(sym_variable_definition, 4),
  [382] = {.count = 1, .reusable = true}, REDUCE(sym_variable_definition, 4),
  [384] = {.count = 1, .reusable = true}, REDUCE(sym__enum_element, 2),
  [386] = {.count = 1, .reusable = true}, SHIFT(152),
  [388] = {.count = 1, .reusable = true}, SHIFT(153),
  [390] = {.count = 1, .reusable = true}, REDUCE(sym_array, 3),
  [392] = {.count = 1, .reusable = true}, REDUCE(sym_parameter_list, 2),
  [394] = {.count = 1, .reusable = true}, SHIFT(155),
  [396] = {.count = 1, .reusable = true}, REDUCE(sym__comma_list_variables, 1),
  [398] = {.count = 1, .reusable = true}, SHIFT(157),
  [400] = {.count = 1, .reusable = true}, REDUCE(sym_return_list, 2),
  [402] = {.count = 1, .reusable = true}, SHIFT(158),
  [404] = {.count = 1, .reusable = true}, REDUCE(sym__comma_list_types, 1),
  [406] = {.count = 1, .reusable = false}, REDUCE(sym_function_signature, 4),
  [408] = {.count = 1, .reusable = true}, REDUCE(sym_function_signature, 4),
  [410] = {.count = 1, .reusable = true}, SHIFT(162),
  [412] = {.count = 1, .reusable = false}, REDUCE(sym_static_assignment, 2),
  [414] = {.count = 1, .reusable = true}, REDUCE(sym_static_assignment, 2),
  [416] = {.count = 1, .reusable = false}, SHIFT(165),
  [418] = {.count = 1, .reusable = false}, REDUCE(sym_string, 3),
  [420] = {.count = 1, .reusable = true}, REDUCE(sym_string, 3),
  [422] = {.count = 1, .reusable = false}, REDUCE(aux_sym_string_repeat1, 2),
  [424] = {.count = 2, .reusable = false}, REDUCE(aux_sym_string_repeat1, 2), SHIFT_REPEAT(131),
  [427] = {.count = 1, .reusable = false}, REDUCE(sym_collection, 3),
  [429] = {.count = 1, .reusable = true}, REDUCE(sym_collection, 3),
  [431] = {.count = 1, .reusable = true}, REDUCE(sym__comma_list_assignment_or_collection_or_value, 2),
  [433] = {.count = 1, .reusable = false}, REDUCE(sym_binary_op, 1),
  [435] = {.count = 1, .reusable = true}, REDUCE(sym_binary_op, 1),
  [437] = {.count = 1, .reusable = false}, REDUCE(sym_group_expression, 3),
  [439] = {.count = 1, .reusable = true}, REDUCE(sym_group_expression, 3),
  [441] = {.count = 1, .reusable = false}, SHIFT(170),
  [443] = {.count = 1, .reusable = true}, SHIFT(170),
  [445] = {.count = 1, .reusable = true}, SHIFT(171),
  [447] = {.count = 1, .reusable = true}, SHIFT(172),
  [449] = {.count = 1, .reusable = false}, SHIFT(174),
  [451] = {.count = 1, .reusable = true}, SHIFT(174),
  [453] = {.count = 1, .reusable = false}, SHIFT(175),
  [455] = {.count = 1, .reusable = false}, REDUCE(sym_single_line_if_statement, 3),
  [457] = {.count = 1, .reusable = true}, REDUCE(sym_single_line_if_statement, 3),
  [459] = {.count = 1, .reusable = false}, REDUCE(sym_character, 3),
  [461] = {.count = 1, .reusable = true}, REDUCE(sym_character, 3),
  [463] = {.count = 1, .reusable = true}, SHIFT(178),
  [465] = {.count = 1, .reusable = true}, SHIFT(179),
  [467] = {.count = 1, .reusable = false}, REDUCE(sym_function_definition, 4),
  [469] = {.count = 1, .reusable = true}, REDUCE(sym_assignment_expression, 3),
  [471] = {.count = 1, .reusable = true}, SHIFT(182),
  [473] = {.count = 1, .reusable = true}, REDUCE(aux_sym_enum_definition_repeat1, 2),
  [475] = {.count = 1, .reusable = true}, SHIFT(184),
  [477] = {.count = 1, .reusable = true}, SHIFT(185),
  [479] = {.count = 2, .reusable = true}, REDUCE(aux_sym_enum_definition_repeat1, 2), SHIFT_REPEAT(114),
  [482] = {.count = 1, .reusable = true}, REDUCE(sym__comma_list_variables, 2),
  [484] = {.count = 1, .reusable = true}, REDUCE(sym_parameter_list, 3),
  [486] = {.count = 1, .reusable = true}, REDUCE(sym__comma_list_types, 2),
  [488] = {.count = 1, .reusable = false}, REDUCE(sym_function_signature, 5),
  [490] = {.count = 1, .reusable = true}, REDUCE(sym_function_signature, 5),
  [492] = {.count = 1, .reusable = false}, REDUCE(sym_variable_definition, 5),
  [494] = {.count = 1, .reusable = true}, REDUCE(sym_variable_definition, 5),
  [496] = {.count = 1, .reusable = true}, SHIFT(193),
  [498] = {.count = 1, .reusable = true}, SHIFT(194),
  [500] = {.count = 1, .reusable = true}, REDUCE(sym_while_statement, 4),
  [502] = {.count = 1, .reusable = true}, REDUCE(aux_sym__comma_list_assignment_or_collection_or_value_repeat1, 2),
  [504] = {.count = 2, .reusable = true}, REDUCE(aux_sym__comma_list_assignment_or_collection_or_value_repeat1, 2), SHIFT_REPEAT(133),
  [507] = {.count = 1, .reusable = true}, SHIFT(196),
  [509] = {.count = 1, .reusable = false}, REDUCE(sym_group_expression, 4),
  [511] = {.count = 1, .reusable = true}, REDUCE(sym_group_expression, 4),
  [513] = {.count = 1, .reusable = false}, SHIFT(197),
  [515] = {.count = 1, .reusable = true}, SHIFT(197),
  [517] = {.count = 1, .reusable = true}, SHIFT(198),
  [519] = {.count = 1, .reusable = true}, SHIFT(199),
  [521] = {.count = 1, .reusable = true}, REDUCE(sym_if_statement, 4),
  [523] = {.count = 1, .reusable = true}, SHIFT(202),
  [525] = {.count = 1, .reusable = true}, SHIFT(203),
  [527] = {.count = 1, .reusable = true}, SHIFT(207),
  [529] = {.count = 1, .reusable = false}, REDUCE(sym_enum_definition, 6),
  [531] = {.count = 1, .reusable = true}, SHIFT(208),
  [533] = {.count = 1, .reusable = true}, REDUCE(aux_sym__comma_list_variables_repeat1, 2),
  [535] = {.count = 2, .reusable = true}, REDUCE(aux_sym__comma_list_variables_repeat1, 2), SHIFT_REPEAT(155),
  [538] = {.count = 1, .reusable = true}, REDUCE(aux_sym__comma_list_types_repeat1, 2),
  [540] = {.count = 2, .reusable = true}, REDUCE(aux_sym__comma_list_types_repeat1, 2), SHIFT_REPEAT(158),
  [543] = {.count = 1, .reusable = false}, REDUCE(sym_function_signature, 6),
  [545] = {.count = 1, .reusable = true}, REDUCE(sym_function_signature, 6),
  [547] = {.count = 1, .reusable = true}, REDUCE(sym_end_while, 2),
  [549] = {.count = 1, .reusable = true}, REDUCE(sym_while_statement, 5),
  [551] = {.count = 1, .reusable = false}, REDUCE(sym_group_expression, 5),
  [553] = {.count = 1, .reusable = true}, REDUCE(sym_group_expression, 5),
  [555] = {.count = 1, .reusable = true}, SHIFT(209),
  [557] = {.count = 1, .reusable = true}, REDUCE(sym_end_if, 2),
  [559] = {.count = 1, .reusable = true}, REDUCE(sym_if_statement, 5),
  [561] = {.count = 1, .reusable = true}, SHIFT(210),
  [563] = {.count = 1, .reusable = false}, SHIFT(211),
  [565] = {.count = 1, .reusable = true}, SHIFT(214),
  [567] = {.count = 1, .reusable = true}, REDUCE(sym_switch_statement, 5),
  [569] = {.count = 2, .reusable = true}, REDUCE(aux_sym_switch_statement_repeat1, 2), SHIFT_REPEAT(178),
  [572] = {.count = 1, .reusable = true}, REDUCE(aux_sym_switch_statement_repeat1, 2),
  [574] = {.count = 1, .reusable = false}, REDUCE(sym_enum_definition, 7),
  [576] = {.count = 1, .reusable = false}, SHIFT(216),
  [578] = {.count = 1, .reusable = true}, SHIFT(219),
  [580] = {.count = 1, .reusable = true}, SHIFT(221),
  [582] = {.count = 1, .reusable = true}, REDUCE(sym_end_switch, 2),
  [584] = {.count = 1, .reusable = true}, REDUCE(sym_switch_statement, 6),
  [586] = {.count = 1, .reusable = true}, SHIFT(222),
  [588] = {.count = 1, .reusable = true}, SHIFT(224),
  [590] = {.count = 1, .reusable = true}, REDUCE(sym_end_default, 2),
  [592] = {.count = 1, .reusable = true}, SHIFT(225),
  [594] = {.count = 1, .reusable = true}, REDUCE(sym_default_statement, 4),
  [596] = {.count = 1, .reusable = true}, REDUCE(sym_end_case, 2),
  [598] = {.count = 1, .reusable = true}, SHIFT(226),
  [600] = {.count = 1, .reusable = true}, REDUCE(sym_case_statement, 5),
  [602] = {.count = 1, .reusable = true}, REDUCE(sym_default_statement, 5),
  [604] = {.count = 1, .reusable = true}, REDUCE(sym_case_statement, 6),
};

#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_marshmallow() {
  static TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .symbol_metadata = ts_symbol_metadata,
    .parse_table = (const unsigned short *)ts_parse_table,
    .parse_actions = ts_parse_actions,
    .lex_modes = ts_lex_modes,
    .symbol_names = ts_symbol_names,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .lex_fn = ts_lex,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
  };
  return &language;
}
