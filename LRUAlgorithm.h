#ifndef LRU_ALGORITHM_H
#define LRU_ALGORITHM_H

using namespace std;

class LRUAlgorithm {
  public:
    LRUAlgorithm();
    ~LRUAlgorithm();
    void use(int index);
    int findBest();
  private:
    int recentlyUsedCount;
};

#endif
