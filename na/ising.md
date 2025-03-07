## Setting


Let $\Lambda=(V,E)$ be a graph, $|V|=N$ is the number of sites.
Let $\mathcal{X}=\{\pm1\}^V$ be the state space or the space of configuration .
Hamiltonian $H:\mathcal{X}\to\mathbb{R}$ is
$$H(\sigma):=-J\sum_{(v,w)\in E}\sigma_v\sigma_w,$$
where $J>0$ is a constant, the positivity implies the ferromagnetic property.
Magnetization $M:\mathcal{X}\to\mathbb{R}$ is
$$M(\sigma):=\frac1N\sum_{v\in V}\sigma_v.$$

For a fixed parameter $\beta>0$,
Gibbs measure is
$$\mu_\beta(\{\sigma\}):=\frac1{Z(\beta)}e^{-\beta H(\sigma)},$$
where $Z(\beta)$ is the partition function
$$Z(\beta):=\sum_{\sigma\in\cX}e^{-\beta H(\sigma)}.$$


Note that $\mu$ depends on $\beta$ and $N$.
We want to compute the limit of $M_*\mu$ as $N\to\infty$.
But we see for each fixed $\beta$ and $N$.


single-flip dynamics
Glauber vs Metropolis
Transition probability
$$p_G(\sigma\to\sigma')=\frac{e^{-\beta(H(\sigma')-H(\sigma))}}{1+e^{-\beta(H(\sigma')-H(\sigma))}}$$
$$p_M(\sigma\to\sigma')=\min\{1,e^{-\beta(H(\sigma')-H(\sigma))}\}$$


Peierls argument
Ising 1D
Onsager 2D