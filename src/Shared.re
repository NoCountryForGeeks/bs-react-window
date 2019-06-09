type direction = 
  | Ltr
  | Rtl;

let parseDirection = direction => switch (direction) {
  | Ltr => "ltr"
  | Rtl => "rtl"
  };

type scrollDirection = 
  | Backward
  | Forward

let parseScrollDirection = scrollDirection => switch (scrollDirection) {
    | "backward" => Backward
    | "forward" => Forward
    | _ => Backward
}