function solution(cards1, cards2, goal) {
  var answer = "";

  let control = "cards1";

  let temp_goal = [...goal];
  let temp_cards1 = [...cards1];
  let temp_cards2 = [...cards2];

  goal.map(() => {
    if (control === "cards1" && cards1.length !== 0) {
      for (let idx = 0; idx < cards1.length; idx++) {
        if (temp_cards1.length > 0) {
          if (goal[idx] === cards1[idx]) {
            temp_cards1.shift();
            temp_goal.shift();
          } else {
            control = "cards2";
            cards1 = [...temp_cards1];
            goal = [...temp_goal];
            break;
          }
        } else {
          control = "cards2";
          cards1 = [...temp_cards1];
          goal = [...temp_goal];
          break;
        }
      }
    }

    if (control === "cards2" && cards2.length !== 0) {
      for (let idx = 0; idx < cards2.length; idx++) {
        if (temp_cards2.length > 0) {
          if (goal[idx] === cards2[idx]) {
            temp_cards2.shift();
            temp_goal.shift();
          } else {
            control = "cards1";
            cards2 = [...temp_cards2];
            goal = [...temp_goal];
            break;
          }
        } else {
          control = "cards1";
          cards2 = [...temp_cards2];
          goal = [...temp_goal];
          break;
        }
      }
    }
  });

  answer = temp_goal.length === 0 ? "Yes" : "No";

  return answer;
}
