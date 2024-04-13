function solution(babbling) {
  var answer = 0;
  const BABY_CAN_BABBLE = ["aya", "ye", "woo", "ma"];

  babbling.map((item) => {
    let babble = item;

    BABY_CAN_BABBLE.filter((item2) => (babble = babble.replace(item2, " ")));

    babble.trim() === "" && answer++;
  });

  return answer;
}
