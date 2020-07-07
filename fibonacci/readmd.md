# 斐波那契问题

## 定义

    F(n) = 0,n=0;

         = 1,n=1;

         = F(n-1)+F(n-2)

## 求解

### 递归算法

```C++
int run_no_cache(int n) {
  if (n == 0)
    return 0;
  else if (n == 1 || n == 2)
    return 1;
  else
    return run_no_cache(n - 1) + run_no_cache(n - 2);
}
```

### 保存中间计算结果

```C++
int run_with_cache(int n) {
  if (n == 0) return 0;
  if (n == 1 || n == 2) return 1;

  static vector<int> cache(n + 1, -1);

  if (cache[n] == -1)  // need calculate
    cache[n] = run_with_cache(n - 1) + run_with_cache(n - 2);
  return cache[n];
}
```
使用函数内的局部静态vector来保存中间数据。