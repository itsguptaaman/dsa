# LeetCode Time Constraints

## 1. Time Constraint hota kya hai?

LeetCode har problem ke liye ek **maximum execution time** set karta hai  
Usually: **~1 second** (kabhi 2 sec, kabhi 0.5 sec)

Matlab:
> Tera code itne operations kare jo 1 second ke andar CPU handle kar le

Agar zyada hua → **TLE (Time Limit Exceeded)**

---

## 2. Golden Rule (MOST IMPORTANT)

Modern CPU approx:

- **10^8 operations per second** handle kar sakta hai (rough estimate)

Isko yaad rakh:
- 1 second ≈ 100,000,000 operations
## 3. Time Complexity vs Input Size (Reality Check)

### O(n)
> n = 10^7 → OK
> n = 10^8 → borderline

### O(n log n)
> n = 10^5 → OK
> n = 10^6 → risky

### O(n^2)
> n = 10^4 → DEAD
> n = 10^3 → maybe

### O(2^n)
> n >= 30 → DEAD DEAD DEAD


# Pratical Usage
> n > 10^8 → O(log n) or O(1)
> n <= 10^8 → O(n)
> n <= 10^6 → O(n log n)
> n <= 10^4 → O(n ^ 2)
> n <= 500 → O(n ^ 3)
> n <= 25 → O(2 ^ n)
> n <= 12 → O(n!)


