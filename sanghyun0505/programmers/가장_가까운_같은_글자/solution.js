function solution(s) {
  const array = [...s];
  var answer = [];

  array.map((_, idx) => {
    answer.push(-1);

    Array.from({ length: idx }).filter((_, idx2) => {
      if (array[idx] === array[idx2]) {
        answer[idx] = idx - idx2;
      }
    });
  });

  return answer;
}
