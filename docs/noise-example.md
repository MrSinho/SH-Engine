## Noise application example

![noise-3](media/noise-3.png)

Using Windows (run as admin):
```bash
python export-application.py name=noise target=EXECUTABLE path=applications/noise
cd applications/noise/windows/build
cmake --build .
cp ../../ini.smd ../bin/ini.smd
```

Using Linux:
```bash
sudo python3.9 export-application.py name=noise target=EXECUTABLE path=applications/noise
cd applications/noise/linux/build
sudo cmake --build .
sudo cp ../../ini.smd ../bin/ini.smd
```

## Application tour

To change the values of the parameters `S` `A` and `B`:

|Parameter    |Increase key    |Decrease key    |
|-------------|----------------|----------------|
| `S`         |       _W_      |       _Q_      |
| `A`         |       _S_      |       _A_      |
| `B`         |       _X_      |       _Z_      |

Fragment shader algorithm:

$$c = \cos(\pi x y s)$$

$$
RGB_{raw} = \begin{bmatrix}
\sin(\pi|x|\cfrac{s}{a}) + c\\
\sin(\pi|y|\cfrac{s}{b}) + c\\
\cos(\pi\cfrac{x}{y}s) + c\\
\end{bmatrix}
$$

---

$s = \cfrac{1}{2}$

$a = 1$

$b = -2,5$

![noise-1](media/noise-1.png)

---

$s = \cfrac{1}{2}$

$a = 1$

$b = -2,5$

![noise-2](media/noise-2.png)

---

$s = 4$

$a = 4,5$

$b = -1,8$

![noise-3](media/noise-3.png)

---

$s = 4$

$a = 5$

$b = 7$

![noise-5](media/noise-5.png)

---
