#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;
int nums[5][5] = {0};
int count = 0;
bool bingo = true;
int row;
int col;
int r;
int turn = 0;
int level[5][5] = {1};
int line=0;

void check() {
  bingo = true; // 
  for (int i = 0; i < 5; i++) {
    bingo = true;                 // 每次迭代都重置 bingo
    for (int k = 0; k < 5; k++) { // 添加 k 的初始值
      if (nums[i][k] != 0) {
        bingo = false;
      }
    }
    if (bingo) {
      line+=1;
      return ;
    }
  }

  for (int i = 0; i < 5; i++) {
    bingo = true;                 // 每次迭代都重置 bingo
    for (int k = 0; k < 5; k++) { // 添加 k 的初始值
      if (nums[k][i] != 0) {
        bingo = false;
      }
    }
    if (bingo) {
      line+=1;
      return ;
    }
  }

  // 檢查斜線是否都為0
  bingo = true;
  for (int i = 0; i < 5; i++) {
    if (nums[i][i] != 0) {
      bingo = false;
      break;
    }
  }
  if (bingo) {
    line+=1;
    return ;
  }

  bingo = true;
  for (int i = 0; i < 5; i++) {
    if (nums[i][4 - i] != 0) {
      bingo = false;
      break;
    }
  }
  if (bingo) {
    line+=1;
    return ;
  }
  return ;
}

//更改等級
void change() {
  for (int i = 0; i < 5; i++) {
    if (level[i][col] != -1) {
      level[i][col] += 1;
    }
  }
  for (int i = 0; i < 5; i++) {
    if (level[row][i] != -1) {
      level[row][i] += 1;
    }
  }
  if (row == col) {
    for (int i = 0; i < 5; i++) {
      if (level[i][i] != -1) {
        level[i][i] += 1;
      }
    }
  }
  if (row == 4 - col) {
    for (int i = 0; i < 5; i++) {
      if (level[i][4 - i] != -1) {
        level[i][4 - i] += 1;
      }
    }
  }
  level[row][col] = -1;
}
//找最大
void findmax() {
  int maxscore = 0;
  for (int i = 0; i < 5; i++) {
    for (int z = 0; z < 5; z++) {
      if (maxscore < level[i][z]) {
        maxscore = level[i][z];
        row = i;
        col = z;
      }
    }
  }
}

int main() {
  cout<<"五條線就贏了\n";
  srand(time(0));
  char player;
  while (count < 25) {
    row = rand() % 5;
    col = rand() % 5;
    if (nums[row][col] == 0) {
      nums[row][col] = count + 1;
      count++;
    }
  }
  //顯示
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cout << nums[i][j] << "\t";
    }
    cout << endl;
  }

  while (true) {
    line=0;
    if (turn == 1) {
      turn = 0;
    } else {
      turn = 1;
    }
    if (turn == 0) {
      findmax();

      cout << "抽出" << nums[row][col] << endl;
      nums[row][col] = 0;
    } else {
      int a;
      cout << "輸入你要劃掉數字";
      cin >> a;
      for (row = 0; row < 5; row++) {
        for (col = 0; col < 5; col++) {
          if (a == nums[row][col]) {
            nums[row][col] = 0;
            break;
          }
        }
        if (a == nums[row][col]) {
          nums[row][col] = 0;
          break;
        }
      }
    }
    level[row][col] = -1;
    change();

    //顯示
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        cout << nums[i][j] << "\t";
      }
      cout << endl;
    }
    check();
    //檢查
    cout << "你bingo了嗎(Y/N))";
    cin >> player;
    if (player == 'y') {
      player = 'Y';
    }
    if (line>=5 && player == 'Y') {
      cout << "平手";
      break;
    } else if (line>=5) {
      cout << "bingo，電腦贏了";
      break;
    } else if (player == 'Y') {
      cout << "你贏了";
      break;
    }
  }
}
