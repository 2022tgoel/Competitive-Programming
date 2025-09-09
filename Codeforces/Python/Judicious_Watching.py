t = int(input())

def solve():
    n, m, q = [int(x) for x in input().split(" ")]
    a = [int(x) for x in input().split(" ")]
    d = [int(x) for x in input().split(" ")]
    l = [int(x) for x in input().split(" ")]
    q = [int(x) for x in input().split(" ")]

    tasks = list(zip(a, d))
    tasks = sorted(tasks, key=lambda x: x[1])

    bt = tasks[-1][1]
    min_start_time = []
    for task in reversed(tasks):
        bt = min(bt - task[0], task[1] - task[0])
        min_start_time.append(bt)

    min_start_time = list(reversed(min_start_time))

    i = 0
    j = 0

    episode_end_time = []
    t = 0

    while i < n or j < m:
        if j < m and (i == n or t + l[j] <= min_start_time[i]):
            t += l[j]
            j += 1
            episode_end_time.append(t)
        else:
            t += tasks[i][0]
            i += 1

    indices = sorted(list(range(len(q))), key=lambda i: q[i])

    ans = [0] * len(q)

    num_episodes = 0

    # print(episode_end_time)
    # print(min_start_time)

    for ind in indices:
        time = q[ind]
        while num_episodes < m and episode_end_time[num_episodes] <= time:
            num_episodes += 1
        ans[ind] = num_episodes

    print(" ".join([str(x) for x in ans]))


for i in range(t):
    solve()