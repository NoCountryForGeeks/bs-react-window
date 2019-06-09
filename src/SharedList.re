type cellProps = {
  index: int,
  style: ReactDOMRe.style,
  /*isScrolling: undefined, true or false It depends on prop useIsScrolling of list*/
  /*data: any, it depends on itemData prop of list*/
}

type internalCellProps = Js.t({
  .
  index: int,
  style: ReactDOMRe.style
});

type direction = 
  | Ltr
  | Rtl;

let parseDirection = direction => switch (direction) {
  | Ltr => "ltr"
  | Rtl => "rtl"
  };

type layout = 
  | Horizontal
  | Vertical;

let parseLayout = layout => switch (layout) {
  | Vertical => "vertical"
  | Horizontal => "horizontal"
  };

type internalOnItemsRendered = Js.t({
  .
  overscanStartIndex: int,
  overscanStopIndex: int,
  visibleStartIndex: int,
  visibleStopIndex: int
})

type onItemsRendered = {
  overscanStartIndex: int,
  overscanStopIndex: int,
  visibleStartIndex: int,
  visibleStopIndex: int
}

let parseOnItemsRendered = (internalOnItemsRendered: internalOnItemsRendered) => {
  let onItemsRendered = {
    overscanStartIndex: internalOnItemsRendered##overscanStartIndex,
    overscanStopIndex: internalOnItemsRendered##overscanStopIndex,
    visibleStartIndex: internalOnItemsRendered##visibleStartIndex,
    visibleStopIndex: internalOnItemsRendered##visibleStopIndex
  }
  onItemsRendered;
}

type scrollDirection = 
  | Backward
  | Forward

type internalOnScroll = Js.t({
  .
  scrollDirection: string,
  scrollOffset: int,
  scrollUpdateWasRequested: bool
})

type onScroll = {
  scrollDirection: scrollDirection,
  scrollOffset: int,
  scrollUpdateWasRequested: bool
}

let parseOnScroll = (internalOnScroll: internalOnScroll) => {
  let scrollDirection = switch (internalOnScroll##scrollDirection) {
    | "backward" => Backward
    | "forward" => Forward
  };

  let onScroll: onScroll = {
    scrollDirection: scrollDirection,
    scrollOffset: internalOnScroll##scrollOffset,
    scrollUpdateWasRequested: internalOnScroll##scrollUpdateWasRequested
  }
  onScroll;
}

let parseChildrenProps = (internalCellProps: internalCellProps) => {
  let cellProps: cellProps = {
    index: internalCellProps##index,
    style: internalCellProps##style
  }
  cellProps;
}