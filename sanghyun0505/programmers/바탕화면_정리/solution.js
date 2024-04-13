function solution(wallpaper) {
  let firstY = null;
  let lastY = null;

  let firstX = null;
  let lastX = null;

  var answer = [];

  [...wallpaper].map((item, idx) => (wallpaper[idx] = [...item]));

  [...wallpaper].map((item, idx) => {
    Array.from({ length: item.length }).map((_, idx2) => {
      if (wallpaper[idx][idx2] === "#") {
        // 첫번째, 마지막 파일의 y좌표 값 구하기
        if (firstY === null) {
          firstY = idx; // firstY가 null일 때 바로 들어오는 #의 y좌표 값이 시작 좌표임
        } else {
          lastY = idx + 1; // 아니라면 모든배열을 순회하며 결국 마지막 #의 y좌표 값에 도달하게 됨
        }

        // 첫 번째 파일의 x좌표 값 구하기
        // idx2가 기존 x좌표 값보다 작을수록 파일이 가장 왼쪽에 있다는 것이 핵심!
        if (firstX === null) {
          firstX = idx2;
        } else if (idx2 < firstX) {
          firstX = idx2;
        }

        // 마지막 파일의 x좌표 값 구하기
        // idx2가 기존 x 좌표 값보다 클수록 파일이 가장 오른쪽에 있다는 것이 핵심!
        if (idx2 + 1 > lastX) {
          lastX = idx2 + 1;
        }
      }
    });
  });

  if (lastY === null) {
    lastY = firstY + 1;
  }

  if (lastX === null) {
    lastX = firstX + 1;
  }

  if (firstY === null && firstX === null) {
    answer = [0, 0, 0, 0];
  } else {
    answer = [firstY, firstX, lastY, lastX];
  }

  return answer;
}
