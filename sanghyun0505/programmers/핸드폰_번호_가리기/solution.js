function solution(phone_number) {
  var answer = [...phone_number];

  Array.from({ length: phone_number.length - 4 }).filter(
    (_, idx) => (answer[idx] = "*")
  );

  return answer.join("");
}
