#include "FullyAssociativeCache.h"

struct fully_associative_cache_row;

FullyAssociativeCache::FullyAssociativeCache(StructReader * reader) {
  this->reader = reader;
  this->rows_count = 128;
  this->rows = (struct row *) malloc(sizeof(struct row) * this->rows_count);
  this->current_timestamp = 0;

  for (int i = 0; i < this->rows_count; i++) {
    this->rows[i].valid_bit = false;
  }
}

FullyAssociativeCache::~FullyAssociativeCache() {
}

void FullyAssociativeCache::start() {
  int get_result = 0;
  int op_result = 0;
  int ops = 0;
  int good_ops = 0;
  mtrace_t tmp;

  while (get_result == 0) {
    get_result = reader->get(&tmp);

    if (!get_result) {
      ops++;

      if (tmp.is_write) {
        op_result = write(tmp.address);
      } else {
        op_result = read(tmp.address);
      }

      if (op_result) {
        good_ops++;
      }

      /* cout << "Pobrano: " << tmp.address << " " << tmp.is_write << " " << +tmp.size << endl; */
    }
  }

  float ratio;
  ratio = float(good_ops) * 100 / ops;
  cout << "Udalo sie " << good_ops << "/" << ops << " (" << ratio << "%)"<< endl;
}

bool FullyAssociativeCache::read(long int address) {
  int addr_ind = find_address(address);
  
  if (addr_ind >= 0) {
    this->rows[addr_ind].timestamp = current_timestamp;
    current_timestamp++;

    return true;
  } else {
    int ind = find_best_index();

    this->rows[ind].valid_bit = true;
    this->rows[ind].address = address;
    this->rows[ind].timestamp = current_timestamp;

    current_timestamp++;

    return false;
  }
}

bool FullyAssociativeCache::write(long int address) {
  return read(address);
}

int FullyAssociativeCache::find_best_index() {
  // search for empty_row
  for (int i = 0; i < this->rows_count; i++) {
    if (this->rows[i].valid_bit == 0) {
      return i;
    }
  }

  // search for lowest timestamp
  // assumption that valid_bit == 1 everywhere
  int min_tmstp = 1000000;
  int min_tmstp_index = -1;
  for (int i = 0; i < this->rows_count; i++) {
    if (this->rows[i].timestamp < min_tmstp) {
      min_tmstp = this->rows[i].timestamp;
      min_tmstp_index = i;
    }
  }

  return min_tmstp_index;
}

int FullyAssociativeCache::find_address(long int address) {
  for (int i = 0; i < this->rows_count; i++) {
    if (this->rows[i].valid_bit && this->rows[i].address == address) {
      return i;
    }
  }
  return -1;
}
