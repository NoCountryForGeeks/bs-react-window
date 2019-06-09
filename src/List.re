include Shared;

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
  let scrollDirection = parseScrollDirection(internalOnScroll##scrollDirection);

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