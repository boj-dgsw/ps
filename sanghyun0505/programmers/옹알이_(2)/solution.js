function solution(babbling) {
  var answer = 0;

  const regex = /(aya|ye|woo|ma)/g;
  const BABY_CAN_BABBLE = ["aya", "ye", "woo", "ma"];

  babbling.map((item) => {
    let babble = item.split(regex).filter((item) => item.trim() !== "");

    babble.map((_, idx) => {
      // 연속되는 옹알이 걸러내기
      if (babble[idx] === babble[idx + 1]) {
        babble[idx] = "1"; // 아무 값으로 1 넣어서 걸러내기
      }
    });

    // babble에 1이 있다는건 애기가 할 수 있는 옹알이가 아님
    if (!"1".includes(babble)) {
      babble.filter((item, idx) => {
        // 아래 조건문을 실행하는 이유는 옹알이 중에 "uuu" 같은 옹알이가 포함되어 있기 때문임
        // item에 애기가 할 수 있는 옹알이가 있다면 해당 babble의 idx에 빈 값을 넣어줌
        if (BABY_CAN_BABBLE.includes(item)) {
          babble[idx] = " ";
        }
      });

      // babble 리스트를 한 문장으로 합쳐, 공백 검사를 실행해서 참이라면
      // 아기가 전부 할 수 있는 옹알이임
      if (babble.join("").trim() === "") {
        answer++;
      }
    }
  });

  return answer;
}
