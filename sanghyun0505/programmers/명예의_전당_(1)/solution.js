function solution(k, score) {
  let hallOfFame = [];

  var answer = [];

  score.map((item) => {
    hallOfFame.sort((a, b) => a - b);

    if (hallOfFame.length === k) {
      if (item > Math.min(...hallOfFame)) {
        hallOfFame[0] = item;
      }
    } else {
      hallOfFame.push(item);
    }

    answer.push(Math.min(...hallOfFame));
  });

  return answer;
}
