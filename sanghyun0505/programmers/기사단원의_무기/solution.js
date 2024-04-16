function solution(number, limit, power) {
  var answer = 0;

  let temp_list = [];
  let list = [];

  const handleRemoveDuplicates = (list) => {
    return [...new Set(list.sort((a, b) => a - b))];
  };

  Array.from({ length: number }).map((_, idx) => {
    Array.from({ length: Math.floor(Math.sqrt(idx + 1)) }).map(
      (_, idx2) => (idx + 1) % (idx2 + 1) === 0 && temp_list.push(idx2 + 1)
    );

    temp_list = handleRemoveDuplicates(temp_list);

    list = [...temp_list];

    temp_list.map((item) => {
      list.push((idx + 1) / item);
    });

    temp_list = [];

    list = handleRemoveDuplicates(list);

    answer += list.length > limit ? power : list.length;
  });

  return answer;
}
