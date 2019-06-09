include Shared;

type cellProps = {
  index: int,
  style: ReactDOMRe.style,
  columnIndex: int, 
  rowIndex: int
  /*isScrolling: undefined, true or false It depends on prop useIsScrolling of list*/
  /*data: any, it depends on itemData prop of list*/
}

type internalCellProps = Js.t({
  .
  index: int,
  style: ReactDOMRe.style,
  columnIndex: int, 
  rowIndex: int
});

let parseChildrenProps = (internalCellProps: internalCellProps) => {
  let cellProps: cellProps = {
    index: internalCellProps##index,
    style: internalCellProps##style,
    columnIndex: internalCellProps##columnIndex, 
    rowIndex: internalCellProps##rowIndex
  }
  cellProps;
}

type internalOnItemsRendered = Js.t({
    .
    overscanColumnStartIndex: int,
    overscanColumnStopIndex: int,
    overscanRowStartIndex: int,
    overscanRowStopIndex: int,
    visibleColumnStartIndex: int,
    visibleColumnStopIndex: int,
    visibleRowStartIndex: int,
    visibleRowStopIndex: int
})

type onItemsRendered = {
    overscanColumnStartIndex: int,
    overscanColumnStopIndex: int,
    overscanRowStartIndex: int,
    overscanRowStopIndex: int,
    visibleColumnStartIndex: int,
    visibleColumnStopIndex: int,
    visibleRowStartIndex: int,
    visibleRowStopIndex: int
}

let parseOnItemsRendered = (internalOnItemsRendered: internalOnItemsRendered) => {
  let onItemsRendered = {
    overscanColumnStartIndex: internalOnItemsRendered##overscanColumnStartIndex,
    overscanColumnStopIndex: internalOnItemsRendered##overscanColumnStopIndex,
    overscanRowStartIndex: internalOnItemsRendered##overscanRowStartIndex,
    overscanRowStopIndex: internalOnItemsRendered##overscanRowStopIndex,
    visibleColumnStartIndex: internalOnItemsRendered##visibleColumnStartIndex,
    visibleColumnStopIndex: internalOnItemsRendered##visibleColumnStopIndex,
    visibleRowStartIndex: internalOnItemsRendered##visibleRowStartIndex,
    visibleRowStopIndex: internalOnItemsRendered##visibleRowStopIndex
  }
  onItemsRendered;
}

type internalOnScroll = Js.t({
  .
  horizontalScrollDirection: string,
  scrollLeft: int,
  scrollTop: int,
  scrollUpdateWasRequested: bool,
  verticalScrollDirection: string
})

type onScroll = {
  horizontalScrollDirection: scrollDirection,
  scrollLeft: int,
  scrollTop: int,
  scrollUpdateWasRequested: bool,
  verticalScrollDirection: scrollDirection
}

let parseOnScroll = (internalOnScroll: internalOnScroll) => {
    let horizontalScrollDirection = parseScrollDirection(internalOnScroll##horizontalScrollDirection);
    let verticalScrollDirection = parseScrollDirection(internalOnScroll##verticalScrollDirection);

    let onScroll: onScroll = {
        horizontalScrollDirection: horizontalScrollDirection,
        scrollLeft: internalOnScroll##scrollLeft,
        scrollTop: internalOnScroll##scrollTop,
        scrollUpdateWasRequested: internalOnScroll##scrollUpdateWasRequested,
        verticalScrollDirection: verticalScrollDirection
    }
    onScroll;
}