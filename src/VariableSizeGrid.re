module InternalVariableSizeGrid = {
  [@bs.module "react-window"] [@react.component]
  external make:
    (
      ~className: string=?,
      ~columnCount: int,
      ~columnWidth: int => int,
      ~direction: string,
      ~estimatedColumnWidth: int=?,
      ~estimatedRowHeight: int=?,
      ~height: int, /* int or string*/
      ~initialScrollLeft: int=?,
      ~initialScrollTop: int=?,
      /*~innerRef: function | createRef object*/
      /*~innerElementType: React$ElementType = "div"*/
      /*~itemData: any*/
      /*~itemKey: function*/
      ~onItemsRendered: (Grid.internalOnItemsRendered => unit)=?,
      ~onScroll: (Grid.internalOnScroll => unit)=?,
      /*~outerRef: function | createRef object*/
      /*~outerElementType: React$ElementType = "div"*/
      ~overscanColumnCount: int=?,
      ~overscanRowCount: int=?,
      ~rowCount: int,
      ~rowHeight: int => int,
      ~style: ReactDOMRe.style=?,
      ~useIsScrolling: bool=?,
      ~width: int, /* int or string*/
      ~children: Grid.internalCellProps => React.element
    ) =>
    React.element = "VariableSizeGrid";
};

[@react.component]
let make =
    (
      ~className: string=?,
      ~columnCount: int,
      ~columnWidth: int => int,
      ~direction: Grid.direction,
      ~estimatedColumnWidth: int=?,
      ~estimatedRowHeight: int=?,
      ~height: int, /* int or string*/
      ~initialScrollLeft: int=?,
      ~initialScrollTop: int=?,
      /*~innerRef: function | createRef object*/
      /*~innerElementType: React$ElementType = "div"*/
      /*~itemData: any*/
      /*~itemKey: function*/
      ~onItemsRendered: (Grid.onItemsRendered => unit)=?,
      ~onScroll: (Grid.onScroll => unit)=?,
      /*~outerRef: function | createRef object*/
      /*~outerElementType: React$ElementType = "div"*/
      ~overscanColumnCount: int=?,
      ~overscanRowCount: int=?,
      ~rowCount: int,
      ~rowHeight: int => int,
      ~style: ReactDOMRe.style=?,
      ~useIsScrolling: bool=?,
      ~width: int, /* int or string*/
      ~children: Grid.cellProps => React.element
    ) => 

    /*Methods*/
    /*scrollTo({scrollLeft: number, scrollTop: number}): void*/
    /*scrollToItem({align: string = "auto", columnIndex?: number, rowIndex?: number }): void*/

  <InternalVariableSizeGrid
    className
    columnCount
    columnWidth
    direction={List.parseDirection(direction)}
    estimatedColumnWidth
    estimatedRowHeight
    height
    initialScrollLeft
    initialScrollTop
    /*innerRef*/
    /*innerElementType*/
    /*itemData*/
    /*itemKey*/
    onItemsRendered={internalOnItemsRendered => onItemsRendered(Grid.parseOnItemsRendered(internalOnItemsRendered))}
    onScroll={internalOnScroll => onScroll(Grid.parseOnScroll(internalOnScroll))}
    /*outerRef*/
    /*outerElementType*/
    overscanColumnCount
    overscanRowCount
    rowCount
    rowHeight
    style
    useIsScrolling
    width
  >
    {internalCellProps => children(Grid.parseChildrenProps(internalCellProps))}
  </InternalVariableSizeGrid>;