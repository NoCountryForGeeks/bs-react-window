[@react.component]
let make = (~cellProps: ReasonWindow.FixedSizeList.cellProps) => {
    <div style=(cellProps.style)>(ReasonReact.string("Cell" ++ string_of_int(cellProps.index)))</div>
}
    