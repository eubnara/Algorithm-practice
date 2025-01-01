use std::collections::{HashMap, LinkedList, VecDeque};

pub fn network_becomes_idle(edges: Vec<Vec<i32>>, patience: Vec<i32>) -> i32 {
    let n = patience.len();
    let mut connected: HashMap<i32, LinkedList<i32>> = HashMap::new();

    // edge 처리하기
    for edge in &edges {
        if !connected.contains_key(&edge[0]) {
            connected.insert(edge[0], LinkedList::new());
        }
        if !connected.contains_key(&edge[1]) {
            connected.insert(edge[1], LinkedList::new());
        }

        connected.get_mut(&edge[0]).unwrap().push_back(edge[1]);
        connected.get_mut(&edge[1]).unwrap().push_back(edge[0]);
    }

    // master server 로부터 최소거리 구하기, BFS
    let mut queue = VecDeque::new();
    queue.push_back(0);

    let mut distance = [-1; 100000];
    distance[0] = 0;

    while !queue.is_empty() {
        let current = queue.pop_front().unwrap();
        for i in connected[&current].iter() {
            if distance[*i as usize] == -1 {
                queue.push_back(*i);
                distance[*i as usize] = distance[current as usize] + 2;
            }
        }
    }

    let mut max = 0;

    // 거리와 patience 를 이용해 모든 경로들에 대한 값들 구하고 최댓값 구하기
    for i in 1..n {
        let msgs = (distance[i] - 1) / patience[i];
        let cur = msgs * patience[i] + distance[i] + 1;

        if cur > max {
            max = cur;
        }
    }

    max
}

fn main() {
    println!(
        "{}",
        network_becomes_idle(vec![vec![0, 1], vec![1, 2]], vec![0, 2, 1])
    );
    println!(
        "{}",
        network_becomes_idle(vec![vec![0, 1], vec![0, 2], vec![1, 2]], vec![0, 10, 10])
    );
    //     edges = [[0,1],[0,2],[1,2]], patience = [0,10,10]
}
