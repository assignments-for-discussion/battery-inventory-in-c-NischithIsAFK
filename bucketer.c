#include <stdio.h>
#include <assert.h>

struct CountsBySoH {
  int healthy;
  int exchange;
  int failed;
};
int calc(int capacity){
    if(capacity>=100){
      return 2;
    } 
    else if(capacity>=80){
    return 1;
    }
    else{
    return 0;
    }
}
struct CountsBySoH countBatteriesByHealth(const int* presentCapacities, int nBatteries) {
  struct CountsBySoH counts = {0, 0, 0};
  for(int i=0;i<nBatteries;i++){
    int soh=calc(presentCapacities[i]);
    switch(soh){
      case 0:counts.failed++;break;
      case 1:counts.exchange++;break;
      case 2:counts.healthy++;break;
    }
  }
  return counts;
}

void testBucketingByHealth() {
  const int presentCapacities[] = {115, 118, 80, 95, 91, 72};
  const int numberOfBatteries = sizeof(presentCapacities) / sizeof(presentCapacities[0]);
  printf("Counting batteries by SoH...\n");
  struct CountsBySoH counts = countBatteriesByHealth(presentCapacities, numberOfBatteries);
  assert(counts.healthy == 2);
  assert(counts.exchange == 3);
  assert(counts.failed == 1);
  printf("Done counting :)\n");
}

int main() {
  testBucketingByHealth();
  return 0;
}
