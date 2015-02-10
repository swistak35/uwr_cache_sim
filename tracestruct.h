
typedef struct trace_record {
  long int address;
  char size;
  bool is_write;
} mtrace_t;
