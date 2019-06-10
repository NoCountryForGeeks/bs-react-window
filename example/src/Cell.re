open ReasonWindow;

[@react.component]
let make = (~cellProps: List.cellProps) => {
    <div style=(cellProps.style)>(ReasonReact.string("Cell" ++ string_of_int(cellProps.index)))</div>
}
    