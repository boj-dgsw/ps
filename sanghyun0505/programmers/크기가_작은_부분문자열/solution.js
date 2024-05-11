function solution(t, p) {
  var answer = 0;
  let substrainArray = [];

  Array.from({ length: t.length }).map((_, idx) => {
    let substrain = [];

    Array.from({ length: p.length }).map((_, idx2) => {
      substrain.push(t[idx + idx2]);
    });

    substrainArray.push(substrain.join(""));
    substrain = [];
  });

  substrainArray.filter(
    (item) => item.length >= p.length && Number(item) <= Number(p) && answer++
  );

  return answer;
}
