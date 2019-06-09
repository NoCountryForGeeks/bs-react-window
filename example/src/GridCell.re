open ReasonWindow;

[@react.component]
let make = (~gridCellProps: Grid.cellProps) => {
    <div style=(gridCellProps.style)>(ReasonReact.string("Cell" ++ string_of_int(gridCellProps.columnIndex) ++ "," ++ string_of_int(gridCellProps.rowIndex)))</div>
}